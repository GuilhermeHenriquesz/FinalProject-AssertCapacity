#include "Sampler.h"

#define ADC_MAX_VALUE 4095U;

uint16_t average;
uint8_t percentage;
uint32_t sum;
uint8_t sampleCount;
uint8_t ready;

void Sampler_Init(void)
{
    average = 0;
    percentage = 0;
    sum = 0;
    sampleCount = 0;
    ready = 0;
}

void Sampler_AddSample(uint16_t sample)
{
    sum += sample;
    sampleCount++;
    if (sampleCount == 100)
    {
        ready = 1;
    }
}

bool Sampler_IsReady(void)
{
    return ready;
}

uint16_t Sampler_GetAverage(void)
{
    average = sum/100U;
    return average;

}

uint8_t Sampler_GetPercent(void)
{
    percentage = (average * 100U) / ADC_MAX_VALUE;
}
