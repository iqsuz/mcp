/*
This header file contains hardware abstration functions and definitions.
Functions need to be updated based on target device.
*/

#ifndef _MCP_SPI_HAL_H_
#define _MCP_SPI_HAL_H_

#include "mcp.h"

/*@brief: This function writes data to SPI shift out register.
@return: MCP_RET enum defined in mcp.h
@param: The data that will be shifted out to target SPI device.*/
MCP_RET _mcp_spi_write(const uint8_t *);

/*@brief: This function reads data from SPI buffer.
@return: Returns read value.
@param: The data address that will be read from SPI buffer.*/
uint8_t _mcp_spi_read(const uint8_t);

/*@brief: This function reads single uint8_t data from MCP address.
@return: Returns read data.
@param: Address that holds the desired data.*/
uint8_t mcp_readregister(const uint8_t);


/*@brief: This function reads data stream from MCP addresses.
@return: MCP_RET enum defined in mcp.h
@param1: Starting address
@param2: Buffer pointers that holds the read values.
@param3: Len of read data.*/
MCP_RET mcp_readregisters(const uint8_t , uint8_t *, uint8_t);

/*@brief: This function writes data to MCP register.
@return: MCP_RET enum defined in mcp.h
@param1: Address
@param2: Data pointer that will be written to address.*/
MCP_RET mcp_writeregister(const uint8_t, const uint8_t *);

/*@brief: This function writes data stream to MCP registers.
@return: MCP_RET enum defined in mcp.h
@param1: Address
@param2: Data pointer that will be written to address.
@param3: Len of write data*/
MCP_RET mcp_writeregisters(const uint8_t, const uint8_t *, uint8_t);

/*@brief: This function drive ChipSelect pin to low to start SPI communication.*/
void _mcp_cs_low(void);

/*@brief: This function drive ChipSelect pin to high to stop SPI communication.*/
void _mcp_cs_high(void);

#endif