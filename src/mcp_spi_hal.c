#include "mcp.h"
#include "mcp_spi_hal.h"


MCP_RET _mcp_spi_write(const uint8_t *data)
{
    
    return MCP_OK;
}

uint8_t _mcp_spi_read(const uint8_t addr)
{
    uint8_t ret_val;
    ret_val = _mcp_spi_write(addr);
    
    return ret_val;
}

uint8_t mcp_readregister(const uint8_t addr)
{
    uint8_t ret_val;
    
    _mcp_cs_low();
    _mcp_spi_write(MCP_SPI_RD);
    _mcp_spi_write(addr);
    ret_val = _mcp_spi_read(MCP_SPI_DUMMY);
    _mcp_cs_high();

    return ret_val;
}

MCP_RET mcp_readregisters(const uint8_t addr, uint8_t *buff, uint8_t len)
{
    _mcp_cs_low();
    _mcp_spi_write(MCP_SPI_RD);
    _mcp_spi_write(addr);

    while(len--)
        *(buff++) = _mcp_spi_read(MCP_SPI_DUMMY); 

    _mcp_cs_high();

    return MCP_OK;
}

MCP_RET mcp_writeregister(const uint8_t addr, const uint8_t *data)
{
    _mcp_cs_low();
    _mcp_spi_write(MCP_SPI_WR);
    _mcp_spi_write(addr);
    _mcp_spi_write(*data);
    _mcp_cs_high();

    return MCP_OK;
}

MCP_RET mcp_writeregisters(const uint8_t addr, const uint8_t *data, uint8_t len)
{
    _mcp_cs_low();
    _mcp_spi_write(MCP_SPI_WR);

    while(len--)
        _mcp_spi_write(*(data++));
    
    _mcp_cs_high();

    return MCP_OK;
}



void _mcp_cs_low()
{

}

void _mcp_cs_high()
{

}