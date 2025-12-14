
#include "stm32n6xx_hal.h"

void Flash_Write(uint32_t addr, uint8_t *data, uint32_t len)
{
    HAL_FLASH_Unlock();
    for (uint32_t i = 0; i < len; i += 8)
    {
        uint64_t qword;
        memcpy(&qword, data + i, 8);
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, addr + i, qword);
    }
    HAL_FLASH_Lock();
}
