#ifndef _MCP_H_
#define _MCP_H_

#include <stdint.h>
	typedef enum{standard_id, extended_id}exide_t;

	struct CanFrame{
		uint32_t can_id;
		exide_t exide;
		uint8_t rtr;
		uint8_t dlc;
		uint8_t can_msg[8]; 
	};
	
	typedef enum{obsolete_frame, fresh_frame}IsObsolote_t;
	
	struct Mailbox{
		uint8_t txbnsidh;
		uint8_t txbnsidl;
		uint8_t txbneid8;
		uint8_t txbneid0;
		IsObsolote_t is_obsolote;
	};


#endif
