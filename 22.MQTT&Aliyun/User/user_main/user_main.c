#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "do_mqtt.h"
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
static uint8_t mqtt_send_ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};
static uint8_t mqtt_recv_ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
  printf("wizchip MQTT_CONNECT_ALIYUN example\r\n");

  /* wizchip init */
  wizchip_initialize();

  /* set network information */
  network_init(ethernet_buf, &default_net_info);

  mqtt_init(SOCKET_ID, mqtt_send_ethernet_buf, mqtt_recv_ethernet_buf);
  while (1)
  {
    do_mqtt();
  }
}
