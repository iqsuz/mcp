#ifndef _MCP_PUZZLE_H_
#define _MCP_PUZZLE_H_
	
#include "mcp.h"

typedef enum{
	MCP_FAIL,
	MCP_OK,
	MCP_PARSER_FAIL
}MCP_RET;

MCP_RET _mcp_puzzle_parsemsg(struct CanFrame *, struct Mailbox *);


#endif
