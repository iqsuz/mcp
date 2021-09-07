#ifndef _MCP_H_
#define _MCP_H_

#include <stdint.h>

//Chip Operation Command Set
#define MCP_RST_CMD (uint8_t)0xC0
#define MCP_BIT_MDFY (uint8_t)0x05
#define MCP_STAT (uint8_t)0xA0

//SPI Operation Command Set
#define MCP_SPI_RD (uint8_t)0x03
#define MCP_SPI_WR (uint8_t)0x02
#define MCP_SPI_DUMMY (uint8_t)0x00

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
}MCP_RET;

typedef enum{standard_id, extended_id}exide_t;
typedef enum{data_frame, remote_frame}rtr_t;

typedef struct{	//Entire CAN frame without data
	uint32_t can_id;
	exide_t exide;
	rtr_t rtr;
	uint8_t dlc;
	uint8_t *data;
	uint8_t data_len;
}CANFrame_t;

typedef enum{obsolete_frame, fresh_frame}is_obsolote_t;

typedef struct{		//Memory location for parsed data.
	uint8_t sidh;
	uint8_t sidl;
	uint8_t eid8;
	uint8_t eid0;
	uint8_t dlc;
	uint8_t *data;
	uint8_t data_len;
}Mailbox_t;

#endif
