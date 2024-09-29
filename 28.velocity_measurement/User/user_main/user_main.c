#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "velocity_measurement.h"

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
uint8_t dest_ip[4] = {192, 168, 1, 20};
uint16_t dest_port = 8080;
uint8_t ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
  printf("wizchip velocity_measurement example\r\n");

  /* wizchip init */
  wizchip_initialize();

  /* set network information */
  network_init(ethernet_buf, &default_net_info);

  /* populate the send content array */
  for (uint16_t i = 0; i < ETHERNET_BUF_MAX_SIZE; i++)
  {
    ethernet_buf[i] = 65 + i % 26;
  }
  /* Set socket0 send and receive cache to 16KB */
  setSn_RXBUF_SIZE(SOCKET_ID, 16);
  setSn_TXBUF_SIZE(SOCKET_ID, 16);
  while (1)
  {
    do_velocity_measurement(SOCKET_ID, ethernet_buf, dest_ip, dest_port);
  }
}
