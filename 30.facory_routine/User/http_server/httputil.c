/**
******************************************************************************
* @file    			httputil.c
* @author  			WIZnet Software Team
* @version 			V1.0
* @date    			2015-12-12
* @brief Useful functions required in http
******************************************************************************
*/
#include "httputil.h"
#include "webpge.h"
#include "utility.h"

#define DEBUG_HTTP
#define SOCK_HTTPS 3
CONFIG_MSG ConfigMsg;
extern char tx_buf[MAX_URI_SIZE];
extern char rx_buf[MAX_URI_SIZE];
extern uint8 reboot_flag;

uint8 boundary[64];
uint8 tmp_buf[1460] = {
	0xff,
};
extern uint8 pub_buf[1024];

/**
 *@brief Set basic configuration information to json_callback
 *@param None
 *@return None
 */
static void make_basic_config_setting_json_callback(int8 *buf, CONFIG_MSG config_msg)
{
	sprintf(buf, "settingsCallback({\"ver\":\"%d.%d\",\
                \"mac\":\"%02X:%02X:%02X:%02X:%02X:%02X\",\
                \"ip\":\"%d.%d.%d.%d\",\
                \"gw\":\"%d.%d.%d.%d\",\
                \"sub\":\"%d.%d.%d.%d\",\
                });",
			config_msg.sw_ver[0], config_msg.sw_ver[1],
			config_msg.mac[0], config_msg.mac[1], config_msg.mac[2], config_msg.mac[3], config_msg.mac[4], config_msg.mac[5],
			config_msg.lip[0], config_msg.lip[1], config_msg.lip[2], config_msg.lip[3],
			config_msg.gw[0], config_msg.gw[1], config_msg.gw[2], config_msg.gw[3],
			config_msg.sub[0], config_msg.sub[1], config_msg.sub[2], config_msg.sub[3]);
}

/**
 *@brief Complete the HTTP response
 *@param None
 *@return None
 */
void do_https(void)
{
	uint8 ch = SOCK_HTTPS; // Define a socket
	uint16 len;

	st_http_request *http_request; // Define a structure pointer
	memset(rx_buf, 0x00, MAX_URI_SIZE);
	http_request = (st_http_request *)rx_buf;
	// http service start
	switch (getSn_SR(ch)) // Get the socket status
	{
	case SOCK_INIT: // The socket is in the initialization state
		listen(ch);
		break;

	case SOCK_LISTEN: // The socket is in a listening state
		break;

	case SOCK_ESTABLISHED: // The socket is connected
		if (getSn_IR(ch) & Sn_IR_CON)
		{
			setSn_IR(ch, Sn_IR_CON); // Clear the break flag
		}
		if ((len = getSn_RX_RSR(ch)) > 0)
		{
			len = recv(ch, (uint8 *)http_request, len); // Receive HTTP requests
			*(((uint8 *)http_request) + len) = 0;
			proc_http(ch, (uint8 *)http_request); // Receives HTTP requests and sends HTTP responses
			disconnect(ch);
		}
		break;

	case SOCK_CLOSE_WAIT: // The socket is in a pending shutdown state
		if ((len = getSn_RX_RSR(ch)) > 0)
		{
			len = recv(ch, (uint8 *)http_request, len); // Receive HTTP requests
			*(((uint8 *)http_request) + len) = 0;
			proc_http(ch, (uint8 *)http_request); // Receives HTTP requests and sends HTTP responses
		}
		disconnect(ch);
		break;

	case SOCK_CLOSED:					 // The socket is closed
		socket(ch, Sn_MR_TCP, 80, 0x00); // Open the socket
		break;

	default:
		break;
	}
}

/**
 *@brief Receives HTTP request packets and sends HTTP responses
 *@param s: HTTP server socket
 *@param buf: parses the packet content
 *@return None
 */
void proc_http(SOCKET s, uint8 *buf)
{
	int8 *name;
	int8 req_name[32] = {
		0x00,
	}; // Define a pointer to an HTTP response packet
	unsigned long file_len = 0; // Defines the struct pointer of the HTTP request header
	uint16 send_len = 0;
	uint8 *http_response;
	st_http_request *http_request;
	memset(tx_buf, 0x00, MAX_URI_SIZE);
	http_response = (uint8 *)rx_buf;
	http_request = (st_http_request *)tx_buf;
	parse_http_request(http_request, buf); // Parse HTTP request headers

	switch (http_request->METHOD)
	{
	case METHOD_ERR: // The request header is incorrect
		memcpy(http_response, ERROR_REQUEST_PAGE, sizeof(ERROR_REQUEST_PAGE));
		send(s, (uint8 *)http_response, strlen((int8 const *)http_response));
		break;

	case METHOD_HEAD: // HEAD request mode

	case METHOD_GET: // GET request method
		name = http_request->URI;
		if (strcmp(name, "/index.htm") == 0 || strcmp(name, "/") == 0 || (strcmp(name, "/index.html") == 0))
		{
			file_len = strlen(INDEX_HTML);
			make_http_response_head((uint8 *)http_response, PTYPE_HTML, file_len);
			send(s, http_response, strlen((char const *)http_response));
			send_len = 0;
			while (file_len)
			{
				if (file_len > 1024)
				{
					if (getSn_SR(s) != SOCK_ESTABLISHED)
					{
						return;
					}
					send(s, (uint8 *)INDEX_HTML + send_len, 1024);
					send_len += 1024;
					file_len -= 1024;
				}
				else
				{
					send(s, (uint8 *)INDEX_HTML + send_len, file_len);
					send_len += file_len;
					file_len -= file_len;
				}
			}
		}

		else if (strcmp(name, "/dream.htm") == 0 || strcmp(name, "/") == 0 || (strcmp(name, "/dream.html") == 0))
		{
			file_len = strlen(DREAM_HTML);
			make_http_response_head((uint8 *)http_response, PTYPE_HTML, file_len);
			send(s, http_response, strlen((char const *)http_response));
			send_len = 0;
			while (file_len)
			{
				if (file_len > 1024)
				{
					if (getSn_SR(s) != SOCK_ESTABLISHED)
					{
						return;
					}
					send(s, (uint8 *)DREAM_HTML + send_len, 1024);
					send_len += 1024;
					file_len -= 1024;
				}
				else
				{
					send(s, (uint8 *)DREAM_HTML + send_len, file_len);
					send_len += file_len;
					file_len -= file_len;
				}
			}
		}

		else if (strcmp(name, "/config.htm") == 0 || strcmp(name, "/") == 0 || (strcmp(name, "/config.html") == 0))
		{
			file_len = strlen(CONFIG_HTML);
			make_http_response_head((uint8 *)http_response, PTYPE_HTML, file_len);
			send(s, http_response, strlen((char const *)http_response));
			send_len = 0;
			while (file_len)
			{
				if (file_len > 1024)
				{
					if (getSn_SR(s) != SOCK_ESTABLISHED)
					{
						return;
					}
					send(s, (uint8 *)CONFIG_HTML + send_len, 1024);
					send_len += 1024;
					file_len -= 1024;
				}
				else
				{
					send(s, (uint8 *)CONFIG_HTML + send_len, file_len);
					send_len += file_len;
					file_len -= file_len;
				}
			}
		}

		else if (strcmp(name, "/w5500.js") == 0)
		{
			memset(tx_buf, 0, MAX_URI_SIZE);
			make_basic_config_setting_json_callback(tx_buf, ConfigMsg);
			sprintf((char *)http_response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s", strlen(tx_buf), tx_buf);
			send(s, (u_char *)http_response, strlen((char const *)http_response));
		}
		break;

	case METHOD_POST:								// POST request
		mid(http_request->URI, "/", " ", req_name); // Get the file name of the request
		if (strcmp(req_name, "config.cgi") == 0)
		{
			// cgi_ipconfig(http_request);												//Write configuration information to the microcontroller EEPROM
			make_cgi_response(5, (int8 *)ConfigMsg.lip, tx_buf); // Generate the text portion of the response
			sprintf((char *)http_response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length:%d\r\n\r\n%s", strlen(tx_buf), tx_buf);
			// Send an HTTP response
			send(s, (u_char *)http_response, strlen((char *)http_response));
			disconnect(s);	 // Disconnect the socket
			reboot_flag = 1; // Restart flag position 1
			return;
		}
		break;

	default:
		break;
	}
}

/**
 *@brief Execute HTTP responses
 *@param None
 *@return None
 */
void make_cgi_response(uint16 delay, int8 *url, int8 *cgi_response_buf)
{
	sprintf(cgi_response_buf, "<html><head><title>iWeb - Configuration</title><script language=javascript>j=%d;function func(){document.getElementById('delay').innerText=' '+j + ' ';j--;setTimeout('func()',1000);if(j==0)location.href='http://%d.%d.%d.%d/';}</script></head><body onload='func()'>please wait for a while, the module will boot in<span style='color:red;' id='delay'></span> seconds.</body></html>", delay, url[0], url[1], url[2], url[3]);
	return;
}
