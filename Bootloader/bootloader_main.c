
#include "stm32n6xx_hal.h"
#include <string.h>

#define APP_ADDRESS 0x08020000
#define SRAM_START  0x20000000
#define SRAM_END    0x20080000

typedef void (*pFunction)(void);

static uint8_t IsApplicationValid(void);
static void JumpToApplication(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    if (IsApplicationValid())
    {
        HAL_Delay(3000);
        JumpToApplication();
    }

    MX_USB_Device_Init();

    while (1)
    {
    }
}

static uint8_t IsApplicationValid(void)
{
    uint32_t sp = *(uint32_t*)APP_ADDRESS;
    return (sp >= SRAM_START && sp <= SRAM_END);
}

static void JumpToApplication(void)
{
    uint32_t jumpAddr = *(uint32_t*)(APP_ADDRESS + 4);
    pFunction appEntry = (pFunction)jumpAddr;

    __disable_irq();
    HAL_DeInit();
    __set_MSP(*(uint32_t*)APP_ADDRESS);
    appEntry();
}
