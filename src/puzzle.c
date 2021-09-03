#include "mcp.h"
#include "mcp_puzzle.h"

MCP_RET _mcp_puzzle_parsemsg(struct CanFrame *frame, struct Mailbox *parsed)
{
    if(frame->exide == extended_id){
        parsed->txbneid0 = (uint8_t)frame->can_id;
        parsed->txbneid8 = (uint8_t)(frame->can_id >> 8);
        parsed->txbnsidl = (uint8_t)(frame->can_id >> 16);
        parsed->txbnsidl = (parsed->txbnsidl & 0x03) | ((parsed->txbnsidl << 3) & 0xE0) | 0x08;
        parsed->txbnsidh = (uint8_t)frame->can_id >> 21;
        parsed->is_obsolote = fresh_frame;
    }else{
        parsed->
    }
}