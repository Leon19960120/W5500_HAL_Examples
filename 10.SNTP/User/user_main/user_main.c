#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "sntp.h"
#include "wiz_interface.h"
#include "do_dns.h"

/*wizchip->STM32 Hardware Pin define*/
//	wizchip_SCS    --->     STM32_GPIOD7
//	wizchip_SCLK	 --->     STM32_GPIOB13
//  wizchip_MISO	 --->     STM32_GPIOB14
//	wizchip_MOSI	 --->     STM32_GPIOB15
//	wizchip_RESET	 --->     STM32_GPIOD8
//	wizchip_INT    --->     STM32_GPIOD9

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
uint8_t sntp_server_name[] = "cn.pool.ntp.org";
uint8_t sntp_server_ip[4] = {162,159,200,1};
uint8_t timezone = 39;//china
datetime date = {0};

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
  printf("wizchip SNTP example\r\n");

  /* wizchip init */
  wizchip_initialize();

  /* set network information */
  network_init(ethernet_buf, &default_net_info);

  if (do_dns(ethernet_buf, sntp_server_name, sntp_server_ip))
  {
    if(sntp_server_ip[0] != 0)
		{
			printf("Use Default Server Internet Protocol Address:%d.%d.%d.%d\r\n",sntp_server_ip[0],sntp_server_ip[1],sntp_server_ip[2],sntp_server_ip[3]);
		}
		else
		{
			printf("No default server address, unable to connect to the server\r\n");
			while(1)
			{
			}
		}
  }
	
  SNTP_init(SOCKET_ID, sntp_server_ip, timezone, ethernet_buf);
	
  while (1)
  {
    if (SNTP_run(&date))
    {
      printf("Beijing time now: %04d-%02d-%02d  %02d:%02d:%02d\r\n", date.yy, date.mo, date.dd, date.hh, date.mm, date.ss);
      break;
    }
  }
}
