#include "mcp.h"
#include "mcp_puzzle.h"

MCP_RET _mcp_puzzle_parseframe(CANFrame_t *frame, Mailbox_t *parsed)
{
    if(frame->exide == extended_id){
        parsed->eid0 = (uint8_t)frame->can_id;
        parsed->eid8 = (uint8_t)(frame->can_id >> 8);
        parsed->sidl = (uint8_t)(frame->can_id >> 16);
        parsed->sidl = (parsed->sidl & 0x03) | ((parsed->sidl << 3) & 0xE0) | 0x08;
        parsed->sidh = (uint8_t)(frame->can_id >> 21);
    }else{
        if((uint32_t)(frame->can_id >> 11))
            return MCP_PARSER_FAIL;
        
        parsed->sidh = (uint8_t)(frame->can_id >> 3);
        parsed->sidl = (uint8_t)(frame->can_id << 5);
        parsed->eid8 = 0x00;
        parsed->eid0 = 0x00;
    }

    parsed->dlc = (frame->rtr << 6) | (frame->dlc & 0x0F);
    return MCP_OK;
}

MCP_RET _mcp_puzzle_concantenateframe(Mailbox_t *parsed, CANFrame_t *frame)
{
    if(parsed->sidl & 0x08){    //if CAN is extended.
        frame->can_id = parsed->sidh;
        frame->can_id <<= 3;
        frame->can_id |= parsed->sidl >> 5;
        frame->can_id <<= 2;
        frame->can_id |= parsed->sidl & 0x03;
        frame->can_id <<= 8;
        frame->can_id |= parsed->eid8;
        frame->can_id <<= 8;
        frame->can_id |= parsed->eid0;
        frame->can_id &= 0x1FFFFFFF;
        
        frame->exide = extended_id;
    }else{
        frame->can_id = parsed->sidh;
        frame->can_id <<= 3;
        frame->can_id |= parsed->sidl >> 5;
        frame->can_id &= 0xFFFFF800;

        frame->exide = standard_id;
    }

    if(parsed->dlc & 0x40)
        frame->rtr = remote_frame;
    else
        frame->rtr = data_frame;

    frame->dlc = parsed->dlc & 0x0F;

    return MCP_OK;
}