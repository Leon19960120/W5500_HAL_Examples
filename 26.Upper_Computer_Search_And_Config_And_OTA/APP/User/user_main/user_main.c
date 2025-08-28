#include <stdint.h>
#include "user_main.h"
#include <stdio.h>
#include "stm32f1xx_hal.h"
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "udp_config.h"
#include "config.h"
#include "fw_update.h"
#include <string.h>
/*wizchip->STM32 Hardware Pin define*/
//	wizchip_SCS    --->     STM32_GPIOD7
//	wizchip_SCLK	 --->     STM32_GPIOB13
//  wizchip_MISO	 --->     STM32_GPIOB14
//	wizchip_MOSI	 --->     STM32_GPIOB15
//	wizchip_RESET	 --->     STM32_GPIOD8
//	wizchip_INT    --->     STM32_GPIOD9

#define ETHERNET_BUF_MAX_SIZE (1024 * 2)

extern CONFIG_MSG system_cfg;
/* network information */
wiz_NetInfo default_net_info = {
    .mac = {0x00, 0x08, 0xdc, 0x12, 0x22, 0x12},
    .ip = {192, 168, 1, 30},
    .gw = {192, 168, 1, 1},
    .sn = {255, 255, 255, 0},
    .dns = {8, 8, 8, 8},
    .dhcp = NETINFO_STATIC // dhcp get ip
                         //.dhcp = NETINFO_STATIC  //static ip
};
uint8_t ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
 
  /* set network information */
printf("APP\r\n");


	 wizchip_initialize();
	system_config_param_get();
    memcpy(&default_net_info.mac, &system_cfg.mac, 6);
    memcpy(&default_net_info.ip, &system_cfg.lip, 4);
    memcpy(&default_net_info.gw, &system_cfg.gw, 4);
    memcpy(&default_net_info.sn, &system_cfg.sub, 4);
    memcpy(&default_net_info.dns, &system_cfg.dns, 4);

    network_init(ethernet_buf, &default_net_info);
  while (1)
  {
    do_udp_config(SOCK_UDP_CONFIG); // Run and precess UpperComputer command.
		fw_update_process();
		if (reboot_flag)
		{
			printf("reboot\r\n");
			system_reboot();
		}
  }
}
