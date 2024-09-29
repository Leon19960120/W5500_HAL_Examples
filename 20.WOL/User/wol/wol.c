#include "wol.h"
#include <stdio.h>
#include "socket.h"
#if _WIZCHIP_ == W5500
#include "w5500.h"
#endif
#if _WIZCHIP_ == W5100S
#include "w5100s.h"
#endif
#define W5100S_WOL 0x08 /**< Wake on Lan */
#define W5500_WOL 0x20  /**< Wake on Lan */

/**
 * @brief  Wake on Lan run function
 * @param  sn: Socket number
 * @param  buf: ethernet buffer pointer
 * @param  local_port: Local port
 * @return none
 **/
void wol_run(uint8_t sn, uint8_t *buf, uint16_t local_port)
{
    uint16_t len = 0;
    uint8_t remote_ip[4] = {0};
    uint16_t remote_port = 0;
#if (_WIZCHIP_ == W5100S)
    switch (getSn_SR(sn))
    {
    case SOCK_UDP:
        if (getSn_IR(sn) & Sn_IR_RECV)
        {
            setSn_IR(sn, Sn_IR_RECV);
        }
        if (getIR2() & 0x01) // Received WOL Magic packet based on UDP.
        {
            printf("get wake on line\r\n");
            setIR2(0x01);
        }
        if ((len = getSn_RX_RSR(sn)) > 0) // Determine if a message has been received
        {
            recvfrom(sn, buf, len, remote_ip, &remote_port); // Receive Data
            printf("%s", buf);
            sendto(sn, buf, len, remote_ip, remote_port); // Send Data
        }
        break;
    case SOCK_CLOSED:
        socket(sn, Sn_MR_UDP, local_port, 0);
        setIMR2(0x01);      // Open WOL magic pack interrupt
        setMR2(W5100S_WOL); // Receive WOL packets
        printf("%d:Opened, UDP WOL, port [%d]\r\n", sn, local_port);
        break;
    }
#elif (_WIZCHIP_ == W5500)
    switch (getSn_SR(sn))
    {
    case SOCK_UDP:
        if (getSn_IR(sn) & Sn_IR_RECV)
        {
            setSn_IR(sn, Sn_IR_RECV);
        }
        if (getIR() & 0x10) // Received WOL Magic packet based on UDP.
        {
            printf("get wake on line\r\n");
            setIR(0x10);
        }
        if ((len = getSn_RX_RSR(sn)) > 0) // Determine if a message has been received
        {
            recvfrom(sn, buf, len, remote_ip, &remote_port); // Receive Data
            printf("%s", buf);
            sendto(sn, buf, len, remote_ip, remote_port); // Send Data
        }
        break;
    case SOCK_CLOSED:
        socket(sn, Sn_MR_UDP, local_port, 0);
        setIMR(0x10);     // Open WOL magic pack interrupt
        setMR(W5500_WOL); // Receive WOL packets
        printf("%d:Opened, UDP WOL, port [%d]\r\n", sn, local_port);
        break;
    }
#endif
}
