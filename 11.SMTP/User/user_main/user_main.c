#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "do_dns.h"
#include "smtp.h"

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

uint8_t smtp_server_name[] = "smtp.126.com"; // The domain name to be resolved using DNS
uint8_t smtp_server_ip[4] = {111,124,203,46};                   // IP address resolved by DNS

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
  printf("wizchip SMTP Example\r\n");

  /* wizchip init */
  wizchip_initialize(); // wizchip init function

  /* set network information */
  network_init(ethernet_buf, &default_net_info);

  mailmessage(); // Mail command information processing
  if (do_dns(ethernet_buf, smtp_server_name, smtp_server_ip))
  {
    if(smtp_server_ip[0] != 0)
		{
			printf("Use Default Server Internet Protocol Address:%d.%d.%d.%d\r\n",smtp_server_ip[0],smtp_server_ip[1],smtp_server_ip[2],smtp_server_ip[3]);
		}
		else
		{
			printf("No default server address, unable to connect to the server\r\n");
			while(1)
			{
			}
		}
  }
  while (1)
  {
		do_smtp(SOCKET_ID, ethernet_buf, smtp_server_ip); // smtp run
	}
}
