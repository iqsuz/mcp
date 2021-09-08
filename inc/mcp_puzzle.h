#ifndef _MCP_PUZZLE_H_
#define _MCP_PUZZLE_H_
	
#include "mcp.h"

/*
@brief 
This function parses given CAN frame according to 
MCP2515 TX registers.

@param struct CANFrame is an entire CAN frame.
@param struct Mailbox is a piece of memory that holds
parsed data.
*/
MCP_RET _mcp_puzzle_parseframe(CANFrame_t *, Mailbox_t *);
MCP_RET _mcp_puzzle_concantenateframe(Mailbox_t *, CANFrame_t *);

#endif
