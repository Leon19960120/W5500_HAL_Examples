#include "HTTP_Server.h"
#include "Webpage.h"
#include <stdio.h>
#include "dhcp.h"
#include "socket.h"
#include "webpage.h"
#include "wizchip_conf.h"
#include "httpServer.h"

#if _WIZCHIP_ == W5100S
#define MAX_SOCKET 4
#elif _WIZCHIP_ == W5500
#define MAX_SOCKET 8
#endif

// http socknumlist
#if _WIZCHIP_ == W5100S
static uint8_t socknumlist[] = {0, 1, 2, 3};
#elif _WIZCHIP_ == W5500
static uint8_t socknumlist[] = {0, 1, 2, 3, 4, 5, 6, 7};
#endif

/**
 * @brief   do HTTP Server
 * @param   http_tx_buffer: Pointer to the HTTP TX buffer
 * @param   http_rx_buffer: Pointer to the HTTP RX buffer
 * @return  none
 */
void W5100S_W5500_HTTP_Server(uint8_t *http_tx_buffer, uint8_t *http_rx_buffer)
{
	reg_httpServer_webContent((uint8_t *)"index.html", (uint8_t *)index_page); // Build HTTP server web pages
	httpServer_init(http_tx_buffer, http_rx_buffer, MAX_SOCKET, socknumlist);  // Initializing the HTTP server

	while (1)
	{
		int i;
		for (i = 0; i < MAX_SOCKET; i++)
		{
			httpServer_run(i); // HTTP server test with three-way socket
		}
	}
}
