#ifndef _MPC_DEFS_H_
#define _MCP_DEFS_H_

//Chip Operation Command Set
#define MCP_RST_CMD     0xC0
#define MCP_BIT_MDFY    0x05
#define MCP_STAT        0xA0

//SPI Operation Command Set
#define MCP_SPI_RD      0x03
#define MCP_SPI_WR      0x02
#define MCP_SPI_DUMMY   0x00

//Register Adresses
#define MCP_TXBn_BASE   0x30
#define _FIND_BASE_REGISTER(x) (MCP_TXBn_BASE + (0x10) * (x))

#define MCP_TXB0CTRL    0x30    //TXB0
#define MCP_TXB0SIDH    0x31
#define MCP_TXB0SIDL    0x32
#define MCP_TXB0EID8    0x33
#define MCP_TXB0EID0    0x34
#define MCP_TXB0DLC     0x35
#define MCP_TXB0D0      0x36
#define MCP_TXB0D1      0x37
#define MCP_TXB0D2      0x38
#define MCP_TXB0D3      0x39
#define MCP_TXB0D4      0x3A
#define MCP_TXB0D5      0x3B
#define MCP_TXB0D6      0x3C
#define MCP_TXB0D7      0x3D

#define MCP_TXB1CTRL    0x40    //TXB1
#define MCP_TXB1SIDH    0x41
#define MCP_TXB1SIDL    0x42
#define MCP_TXB1EID8    0x43
#define MCP_TXB1EID0    0x44
#define MCP_TXB1DLC     0x45
#define MCP_TXB1D0      0x46
#define MCP_TXB1D1      0x47
#define MCP_TXB1D2      0x48
#define MCP_TXB1D3      0x49
#define MCP_TXB1D4      0x4A
#define MCP_TXB1D5      0x4B
#define MCP_TXB1D6      0x4C
#define MCP_TXB1D7      0x4D

#define MCP_TXB2CTRL    0x50    //TXB2
#define MCP_TXB2SIDH    0x51
#define MCP_TXB2SIDL    0x52
#define MCP_TXB2EID8    0x53
#define MCP_TXB2EID0    0x54
#define MCP_TXB2DLC     0x55
#define MCP_TXB2D0      0x56
#define MCP_TXB2D1      0x57
#define MCP_TXB2D2      0x58
#define MCP_TXB2D3      0x59
#define MCP_TXB2D4      0x5A
#define MCP_TXB2D5      0x5B
#define MCP_TXB2D6      0x5C
#define MCP_TXB2D7      0x5D

#endif
