#include "mcp_spi_hal.h"
#include "mcp_controller.h"



void mcp_reset()
{
    _mcp_spi_write(MCP_RST_CMD);
}

uint8_t mcp_readstatus()
{
    uint8_t ret_val;
    
    _mcp_cs_low();
    _mcp_spi_write(MCP_STAT);
    ret_val = _mcp_spi_read(MCP_SPI_DUMMY);
    _mcp_cs_high();

    return ret_val;
}

static void _mcp_bitmodify(const uint8_t addr, uint8_t mask, const uint8_t data)
{
    _mcp_cs_low();
    _mcp_spi_write(MCP_BIT_MDFY);
    _mcp_spi_write(addr);
    _mcp_spi_write(mask);
    _mcp_spi_write(data);
    _mcp_cs_high();
}

MCP_RET mcp_send(uint8_t tx_buff, const Mailbox_t *mailbox)
{

}

MCP_RET mcp_is_txavailable(MCP_TXBn tx_buff)
{
    uint8_t stat = mcp_readstatus();

    switch (tx_buff){
        case TXB0:
            return (stat & 0x04) ? MCP_OK : MCP_TX_BUSY;
        case TXB1:
            return (stat & 0x10) ? MCP_OK : MCP_TX_BUSY;
        case TXB2:
            return (stat & 0x40) ? MCP_OK : MCP_TX_BUSY;
        default:
            return MCP_FAIL;
    }
}

uint8_t mcp_readstatus()
{
    uint8_t stat;

    _mcp_cs_low();
    _mcp_spi_write(MCP_STAT);
    stat =_mcp_spi_read(MCP_SPI_DUMMY);
    _mcp_cs_high();

    return stat;
}

func