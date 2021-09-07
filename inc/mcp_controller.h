#ifndef _MCP_CONTROLLER_H_
#define _MCP_CONTROLLER_H_

#include <stdint.h>

void mcp_reset(void);
uint8_t mcp_readregister(const uint8_t *, uint8_t *);


#endif