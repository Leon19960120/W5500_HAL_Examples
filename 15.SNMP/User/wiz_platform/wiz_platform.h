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
 * @brief Get user LED status
 * @param ptr :Pointer to the buffer where the LED status string is stored
 * @param len :Pointer to store LED status string length
 */
void get_user_led_status(void *ptr, uint8_t *len);

/**
 * @brief Set user LED status
 * @param val LED status value
 *        - 0: turn off LED
 *        - 1: turn on LED
 */
void set_user_led_status(int32_t val);
#endif
