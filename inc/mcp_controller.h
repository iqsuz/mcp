#ifndef _MCP_CONTROLLER_H_
#define _MCP_CONTROLLER_H_

#include <stdint.h>

void mcp_reset(void);
uint8_t mcp_readstatus(void);
static void _mcp_bitmodify(const uint8_t, const uint8_t, const uint8_t);
MCP_RET mcp_send(const MCP_TXBn, const Mailbox_t *);
MCP_RET mcp_is_txavailable(const MCP_TXBn);
uint8_t mcp_readstatus(void);

#endif