#include <stdint.h>
#include <ctype.h>
#include <string.h>

#include "SerialCmd.h"
#include "Bsp.h"
#include "usart.h"

static uint8_t rxByte;
static char uartCommand[10];
static uint8_t indexCh = 0;
static char uartCommand[10];

uint8_t SerialCmd_SelectedLed(void)
{
    SerialCmd_ToUpper(uartCommand);

    if (strcmp(uartCommand, "LED1") == 0)
    {
        return 1;
    }

    if (strcmp(uartCommand, "LED2") == 0)
    {
        return 2;
    }

    if (strcmp(uartCommand, "LED3") == 0)
    {
        return 3;
    }

    return 0;

}

void SerialCmd_UartRxHandler(void)
{
    if (rxByte == '\r' || rxByte == '\n')
    {
        uartCommand[indexCh] = '\0';
        indexCh = 0;
        Bsp_SetUartFlag();
    }
    else
    {
        uartCommand[indexCh++] = rxByte;

        if (indexCh >= sizeof(uartCommand) - 1)
        {
            indexCh = 0;
        }
    }

    HAL_UART_Receive_IT(&huart3, &rxByte, 1);
}

void SerialCmd_ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper((unsigned char)*str);
        str++;
    }
}
