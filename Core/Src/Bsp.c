#include "Bsp.h"
#include "main.h"
#include "adc.h"
#include "eth.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

volatile uint8_t samplerFlag;
volatile uint8_t debounceFlag;
volatile uint8_t buttonFlag;
volatile uint8_t uartFlag;



void Bsp_Init()
{
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_ETH_Init();
    MX_TIM3_Init();
    MX_TIM6_Init();
    MX_TIM7_Init();
    MX_USART3_UART_Init();
    MX_USB_OTG_FS_PCD_Init();
    MX_TIM1_Init();
    MX_TIM4_Init();
    MX_TIM12_Init();

    HAL_TIM_Base_Start_IT(&htim6);
    HAL_TIM_Base_Start_IT(&htim7);
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_1);

    samplerFlag = 0;
    debounceFlag = 0;
    buttonFlag = 0;
    uartFlag = 0;
}

uint16_t Bsp_ReadAdc(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    return (uint16_t) HAL_ADC_GetValue(&hadc1);
}

void Bsp_SetPwmDutyCycle(uint8_t ledId, uint8_t dutyCycle)
{
    uint32_t compare;

    if (ledId == 1)
    {
        compare = (dutyCycle * (__HAL_TIM_GET_AUTORELOAD(&htim3) + 1U)) / 100U;
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, compare);
    }

    else if (ledId == 2)
    {
        compare = (dutyCycle * (__HAL_TIM_GET_AUTORELOAD(&htim12) + 1U)) / 100U;
        __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_1, compare);
    }

    else if (ledId == 3)
    {
        compare = (dutyCycle * (__HAL_TIM_GET_AUTORELOAD(&htim4) + 1U)) / 100U;
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, compare);
    }


}

uint8_t Bsp_GetSamplingFlag(void)
{
    return samplerFlag;
}

void Bsp_ClearSamplingFlag(void)
{
    samplerFlag = 0;
}

void Bsp_SetSamplingFlag(void)
{
    samplerFlag = 1;
}

uint8_t Bsp_GetDebounceFlag(void)
{
    return debounceFlag;
}

void Bsp_ClearDebounceFlag(void)
{
    debounceFlag = 0;
}

void Bsp_SetDebounceFlag(void)
{
    debounceFlag = 1;
}

uint8_t Bsp_GetButtonFlag(void)
{
    return buttonFlag;
}

void Bsp_ClearButtonFlag(void)
{
    buttonFlag = 0;
}

void Bsp_SetButtonFlag(void)
{
    buttonFlag = 1;
}

uint8_t Bsp_GetUartFlag(void)
{
    return uartFlag;
}

void Bsp_ClearUartFlag(void)
{
    uartFlag = 0;
}

void Bsp_SetUartFlag(void)
{
    uartFlag = 1;
}

















