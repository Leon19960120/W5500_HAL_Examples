#ifndef __WIZ_PLATFORM_H__
#define __WIZ_PLATFORM_H__

#include <stdint.h>

/**
 * @brief   hardware reset wizchip
 * @param   none
 * @return  none
 */
void wizchip_reset(void);

/**
 * @brief   Register the WIZCHIP SPI callback function
 * @param   none
 * @return  none
 */
void wizchip_spi_cb_reg(void);

/**
 * @brief   Turn on wiz timer interrupt
 * @param   none
 * @return  none
 */
void wiz_tim_irq_enable(void);

/**
 * @brief   Turn off wiz timer interrupt
 * @param   none
 * @return  none
 */
void wiz_tim_irq_disable(void);

/**
 * @brief   Get a character from the keyboard
 * @param   val:Get timeout
 * @return  retrieved character
 */
uint8_t get_char(uint32_t val);
#endif
