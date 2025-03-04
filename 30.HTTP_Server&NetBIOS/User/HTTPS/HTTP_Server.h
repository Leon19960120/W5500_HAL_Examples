#ifndef __HTTP_SERVER__
#define __HTTP_SERVER__

#include "main.h"

/**
 * @brief   do HTTP Server
 * @param   http_tx_buffer: Pointer to the HTTP TX buffer
 * @param   http_rx_buffer: Pointer to the HTTP RX buffer
 * @return  none
 */
void W5100S_W5500_HTTP_Server(uint8_t *http_tx_buffer, uint8_t *http_rx_buffer);

#endif
