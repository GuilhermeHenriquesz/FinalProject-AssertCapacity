#include <stdint.h>

#include "LedPwm.h"
#include "Bsp.h"

void LedPwm_SetDuty(uint8_t ledId, uint8_t dutyCycle)
{

    Bsp_SetPwmDutyCycle(ledId, dutyCycle);

}

uint8_t LedPwm_GetDuty(uint8_t ledId)
{
    uint8_t* dutyCycles = Bsp_GetPwmDutyCycle();
    if (ledId == 1)
    {
        return dutyCycles[0];
    }

    else if (ledId == 2)
    {
        return dutyCycles[1];
    }

    else if (ledId == 3)
    {
        return dutyCycles[2];
    }

    return 0;


}
