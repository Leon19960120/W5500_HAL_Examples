#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "tftp_client.h"
#include "tftp.h"

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

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
  printf("wizchip TFTP Client example\r\n");

  /* wizchip init */
  wizchip_initialize();

  /* set network information */
  network_init(ethernet_buf, &default_net_info);
	
	/* Register for TFTP timeout interrupts	*/
	wiz_add_timer(tftp_timeout_handler,1000);
	
  do_tftp_client(SOCKET_ID,ethernet_buf);
	
	wiz_delete_timer(tftp_timeout_handler);
  while (1)
	{
	}
}
