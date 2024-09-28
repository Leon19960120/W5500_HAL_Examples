#ifndef __BSP_PORT_H__
#define __BSP_PORT_H__

#include <stdint.h>

/**
 * @brief   hardware reset wizchip
 * @param   none
 * @return  none
 */
void wizchip_reset(void);

/**
 * @brief   wizchip spi callback register
 * @param   none
 * @return  none
 */
void wizchip_spi_cb_reg(void);

/**
 * @brief   user delay ms
 * @param   nms:delay ms
 * @return  none
 */
void user_delay_ms(uint32_t nms);

/**
 * @brief   Turn on Timer 2 interrupt
 * @param   htim : timer
 * @return  none
 */
void tim2_irq_enable(void);

/**
 * @brief   Turn off Timer 2 interrupt
 * @param   htim : timer
 * @return  none
 */
void tim2_irq_disable(void);

/**
 * @brief   Get a character from the keyboard
 * @param   val:Get timeout
 * @return  retrieved character
 */
uint8_t get_char(uint32_t val);

/**
 * @brief   Set user LED status
 * @param   val:1:SET,0:RESET
 * @return  none
 */
void setUserLEDStatus(uint8_t val);
#endif
