#include "user_main.h"
#include <stdio.h>
#include <stdint.h>
#include "wizchip_conf.h"
#include "wiz_interface.h"
#include "wiz_platform.h"
#include "UPnP.h"

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

static uint16_t tcps_port = 8000;
static uint16_t udps_port = 5000;
static uint8_t tx_size[_WIZCHIP_SOCK_NUM_] = {4, 4, 2, 1, 1, 1, 1, 2};
static uint8_t rx_size[_WIZCHIP_SOCK_NUM_] = {4, 4, 2, 1, 1, 1, 1, 2};
static uint8_t ethernet_buf[ETHERNET_BUF_MAX_SIZE] = {0};

/**
 * @brief   User Run Program
 * @param   none
 * @return  none
 */
void user_run(void)
{
  printf("wizchip UPnP example\r\n");

  /* wizchip init */
  wizchip_initialize();

  /* socket rx and tx buff init */
  wizchip_init(tx_size, rx_size);

  /* set network information */
  network_init(ethernet_buf, &default_net_info);

  UserLED_Control_Init(setUserLEDStatus);

	wiz_add_timer(data_process_count_handle,1000);
  do
  {
    printf("Send SSDP.. \r\n");
  } while (SSDPProcess(SOCKET_ID) != 0); // SSDP Search discovery

  if (GetDescriptionProcess(SOCKET_ID) == 0) // GET IGD description
  {
    printf("GetDescription Success!!\r\n");
  }
  else
  {
    printf("GetDescription Fail!!\r\n");
  }

  if (SetEventing(SOCKET_ID) == 0) // Subscribes IGD event messageS
  {
    printf("SetEventing Success!!\r\n");
  }
  else
  {
    printf("SetEventing Fail!!\r\n");
  }

  Main_Menu(SOCKET_ID, SOCKET_ID + 1, SOCKET_ID + 2, ethernet_buf, tcps_port, udps_port); // Main menu
  while (1)
  {
		
	}
}
