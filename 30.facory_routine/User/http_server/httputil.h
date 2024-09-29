#ifndef __HTTPUTIL_H__
#define __HTTPUTIL_H__

#include <stdio.h>
#include <string.h>
#include "w5500.h"
#include "utility.h"
#include "http_server.h"
#include "socket.h"

typedef struct _CONFIG_MSG
{
  uint8 mac[6];
  uint8 lip[4];
  uint8 sub[4];
  uint8 gw[4];
  uint8 dns[4];
  uint8 rip[4];
  uint8 sw_ver[2];
} CONFIG_MSG;
void proc_http(SOCKET s, u_char *buf);
void do_https(void);

uint16 make_msg_response(uint8 *buf, int8 *msg);

void make_cgi_response(uint16 a, int8 *b, int8 *c);
void make_pwd_response(int8 isRight, uint16 delay, int8 *cgi_response_content, int8 isTimeout);
#endif
