#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "ftpc.h"
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

/* Destination Internet Protocol Address and Port Number */
uint8_t ftp_ip[4] = {192, 168, 1, 20};
static uint8_t ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
  printf("wizchip FTP Client example\r\n");

  /* wizchip init */
  wizchip_initialize(); // wizchip init function

  /* set network information */
  network_init(ethernet_buf, &default_net_info);

  /* ftp client init */
  ftpc_init(ftp_ip, SOCKET_CTRL, SOCKET_DATA);
  while (1)
  {
    ftpc_run(ethernet_buf);
  }
}
