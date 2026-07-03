#include <stdint.h>

#include "LedPwm.h"
#include "Bsp.h"

void LedPwm_SetDuty(uint8_t ledId, uint8_t dutyCycle)
{
    if (dutyCycle > 100)
    {
        dutyCycle = 100;
    }

    Bsp_SetPwmDutyCycle(ledId, dutyCycle);

}
