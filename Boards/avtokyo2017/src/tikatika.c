#include <tikatika.h>
#include <main.h>

static void delay(unsigned int ii)
{
    unsigned int jj;
    for (jj = ii; jj > 0; jj--)
        asm("nop");
}

void tikatikaInit()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

    /*Configure GPIO pin : PB13 */
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
void tikatika()
{
    while (1)
    {
        int wait = DELAY_COUNT;
        for (int i = 1; i <= 12; i++)
        {
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
            delay(wait);
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
            delay(wait);
            wait *= 2;
        }
    }
}
