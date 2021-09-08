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

static void _mcp_bitmodify(const uint8_t addr, const uint8_t mask, const uint8_t data)
{
    _mcp_cs_low();
    _mcp_spi_write(MCP_BIT_MDFY);
    _mcp_spi_write(addr);
    _mcp_spi_write(mask);
    _mcp_spi_write(data);
    _mcp_cs_high();
}

MCP_RET mcp_send(const MCP_TXBn tx_buff, const Mailbox_t *mailbox)
{
    int base_addr = _FIND_BASE_REGISTER(tx_buff);
    
    if(mcp_is_txavailable(tx_buff) != MCP_OK)
        return MCP_TX_BUSY;

    if(mailbox->dlc > 8 && mailbox->dlc < 0)
        return MCP_DATA_LEN_FAIL;
    
    mcp_writeregister((base_addr + 0x01), &(mailbox->sidh));
    mcp_writeregister((base_addr + 0x02), &(mailbox->sidl));
    mcp_writeregister((base_addr + 0x03), &(mailbox->eid8));
    mcp_writeregister((base_addr + 0x04), &(mailbox->eid0));
    mcp_writeregister((base_addr + 0x05), &(mailbox->dlc));

}

MCP_RET mcp_is_txavailable(const MCP_TXBn tx_buff)
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
