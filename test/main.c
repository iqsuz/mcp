#include <stdio.h>
#include <stdlib.h>
#include "../inc/mcp.h"
#include "../inc/mcp_puzzle.h"


int main(int argc, char const *argv[])
{
    CANFrame_t can_frame;
    CANFrame_t can_frame2;
    MCP_RET ret_val;
    
    can_frame.can_id = 0x01FB6912;
    can_frame.exide = extended_id;
    can_frame.rtr = remote_frame;
    can_frame.dlc = 0x04;

    Mailbox_t parsed_frame;

    ret_val = _mcp_puzzle_parseframe(&can_frame, &parsed_frame);

    if(ret_val != MCP_OK){
        printf("Parsing failed with error code of %d\n", ret_val);
        exit(-1);
    }
    
    _mcp_puzzle_concantenateframe(&parsed_frame, &can_frame2);

    printf("SIDH = %x\nSIDL = %x\nEID8 = %x\nEID0 = %x\nDLC = %x\nOBSOLESNESS = %x\n", parsed_frame.txbnsidh, parsed_frame.txbnsidl, \
    parsed_frame.txbneid8, parsed_frame.txbneid0, parsed_frame.txbndlc, parsed_frame.is_obsolote);

    printf("Concantenated Frame...\n\n");

    printf("CAN ID = %x\n", can_frame2.can_id);

    return 0;
}