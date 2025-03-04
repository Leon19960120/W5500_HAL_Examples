#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "httpServer.h"
#include "Webpage.h"
#include "netbios.h"

/*wizchip->STM32 Hardware Pin define*/
//	wizchip_SCS    --->     STM32_GPIOD7
//	wizchip_SCLK	 --->     STM32_GPIOB13
//  wizchip_MISO	 --->     STM32_GPIOB14
//	wizchip_MOSI	 --->     STM32_GPIOB15
//	wizchip_RESET	 --->     STM32_GPIOD8
//	wizchip_INT    --->     STM32_GPIOD9

#if _WIZCHIP_ == W5500
#define SOCK_NETBIOS 7
#elif _WIZCHIP_ == W5100S
#define SOCK_NETBIOS 3
#endif

/* network information */
wiz_NetInfo default_net_info = {
    .mac = {0x00, 0x08, 0xdc, 0x12, 0x22, 0x12},
    .ip = {192, 168, 1, 212},
    .gw = {192, 168, 1, 1},
    .sn = {255, 255, 255, 0},
    .dns = {8, 8, 8, 8},
    .dhcp = NETINFO_DHCP // dhcp get ip
    //.dhcp = NETINFO_STATIC  //static ip
};
static uint8_t ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};
static uint8_t http_tx_ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};
static uint8_t http_rx_ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};
#if (_WIZCHIP_ == W5500)
static uint8_t socknumlist[] = {0, 1, 2, 3, 4, 5, 6};
#elif (_WIZCHIP_ == W5100S)
static uint8_t socknumlist[] = {0, 1, 2};
#endif
/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
	wiz_NetInfo net_info;
  printf("wizchip HTTP Server example\r\n");

  /* wizchip init */
  wizchip_initialize(); // wizchip init function

  /* set network information */
  network_init(ethernet_buf, &default_net_info);
	
	reg_httpServer_webContent((uint8_t *)"index.html", (uint8_t *)index_page); // Build HTTP server web pages
	httpServer_init(http_tx_ethernet_buf, http_rx_ethernet_buf, _WIZCHIP_SOCK_NUM_-1, socknumlist);  // Initializing the HTTP server
	
	wizchip_getnetinfo(&net_info);
	printf("Please enter% d.% d.% d.% d in your browser to access the HTTP server\r\n",net_info.ip[0],net_info.ip[1],net_info.ip[2],net_info.ip[3]);
  while (1)
	{
		int i;
		for (i = 0; i < _WIZCHIP_SOCK_NUM_-1; i++)
		{
			httpServer_run(i); // HTTP server test with three-way socket
		}
		do_netbios(SOCK_NETBIOS);
	}
}
