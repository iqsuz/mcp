#ifndef _MCP_PUZZLE_H_
#define _MCP_PUZZLE_H_
	
#include "mcp.h"

typedef enum{
	MCP_FAIL,
	MCP_OK,
	MCP_PARSER_FAIL
}MCP_RET;

MCP_RET _mcp_parser(struct CanMsg *msg, struct Mailbox *parsed)
{
	if(msg->exide == 1){
			
	}else{
	
	}
}


#endif
