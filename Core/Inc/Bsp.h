#include <stdint.h>

void Bsp_Init(void);

uint16_t Bsp_ReadAdc(void);

void Bsp_SetPwmDutyCycle(uint8_t ledId, uint8_t dutyCycle);
uint8_t* Bsp_GetPwmDutyCycle();

uint8_t Bsp_GetSamplingFlag(void);
void Bsp_ClearSamplingFlag(void);
void Bsp_SetSamplingFlag(void);

uint8_t Bsp_GetDebounceFlag(void);
void Bsp_ClearDebounceFlag(void);
void Bsp_SetDebounceFlag(void);

uint8_t Bsp_GetButtonFlag(void);
void Bsp_ClearButtonFlag(void);
void Bsp_SetButtonFlag(void);

uint8_t Bsp_GetUartFlag(void);
void Bsp_ClearUartFlag(void);
void Bsp_SetUartFlag(void);


char *Bsp_GetUartCommand(void);

void Bsp_UartRxHandler();







