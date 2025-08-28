#include <stdint.h>
#include <string.h>
#include "stm32f1xx_hal.h"
#include "flash.h"
#include "stm32f1xx_hal_flash.h"
#include "stm32f1xx_hal_flash_ex.h"

void flash_erase(uint32_t address, uint32_t length)
{
     FLASH_EraseInitTypeDef EraseInitStruct;
    uint32_t PageError;
    HAL_StatusTypeDef status;
    uint32_t page_num;
    uint32_t first_page;
    uint32_t end_address = address + length - 1;

    // 计算起始页和结束页
    first_page = (address - FLASH_BASE) / FLASH_PAGE_SIZE;
    page_num = ((end_address - FLASH_BASE) / FLASH_PAGE_SIZE) - first_page + 1;

    HAL_FLASH_Unlock();

    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.PageAddress = FLASH_BASE + (first_page * FLASH_PAGE_SIZE);
    EraseInitStruct.NbPages = page_num;

    // 执行擦除操作
    status = HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);
    if (status != HAL_OK) {
        // 错误处理（可选）
    }

    HAL_FLASH_Lock();
}

void flash_write(uint32_t address, uint8_t *data, uint32_t length)
{
    uint32_t i;
    uint32_t write_data;
    uint32_t write_address = address;

    HAL_FLASH_Unlock();

    for (i = 0; i < length; i += 4)
    {
        memcpy(&write_data, data + i, 4);
        
        // 使用HAL库的编程函数
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, write_address, write_data) != HAL_OK) {
            // 编程错误处理（可选）
            break;
        }
        write_address += 4;
    }

    HAL_FLASH_Lock();
}

void flash_read(uint32_t address, uint8_t *data, uint32_t length)
{
    uint32_t i;

    for (i = 0; i < length; i++)
    {
        data[i] = *(__IO uint8_t *)(address + i);
    }
}
