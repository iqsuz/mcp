#ifndef _MCP_H_
#define _MCP_H_

#include <stdint.h>
#include "mcp_defs.h"

typedef enum{
	TXB0,
	TXB1,
	TXB2
}MCP_TXBn;


typedef enum{	//define all function returns.
	MCP_FAIL,
	MCP_OK,
	MCP_PARSER_FAIL,
	MCP_TX_BUSY,
	MCP_DATA_LEN_FAIL,
}MCP_RET;

typedef enum{standard_id, extended_id}exide_t;
typedef enum{data_frame, remote_frame}rtr_t;

typedef struct{	//Entire CAN frame without data
	uint32_t can_id;
	exide_t exide;
	rtr_t rtr;
	uint8_t dlc;
	uint8_t *data;
}CANFrame_t;

typedef enum{obsolete_frame, fresh_frame}is_obsolote_t;

typedef struct{		//Memory location for parsed data.
	uint8_t sidh;
	uint8_t sidl;
	uint8_t eid8;
	uint8_t eid0;
	uint8_t dlc;
	uint8_t *data;
}Mailbox_t;

#endif
