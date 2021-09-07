#ifndef _MCP_SPI_HAL_H_
#define _MCP_SPI_HAL_H_

#include "mcp.h"

void _mcp_spi_write(const uint8_t *);
uint8_t _mcp_spi_read(const uint8_t);
void _mcp_cs_low(void);
void _mcp_cs_high(void);

#endif