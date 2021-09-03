#ifndef _MCP_H_
#define _MCP_H_

#include <stdint.h>

	struct CanMsg{
		uint32_t can_id;
		uint8_t exide;
		uint8_t rtr;
		uint8_t dlc;
		uint8_t can_msg[8]; 
	};
	
	
	typedef enum{msg_obsolote, msg_non_obsoloete}IsObsolote_t;
	
	struct Mailbox{
		uint8_t txbnsidh;
		uint8_t txbnsidl;
		uint8_t txbneid8;
		uint8_t txbneid0;
		IsObsolote_t is_obsolote;
	};


#endif
