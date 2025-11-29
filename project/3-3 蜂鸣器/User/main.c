#include "stm32f10x.h" // Device header
#include "Delay.h"

int main(void)
{
    /* 开启GPIOB时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* 将PB12配置为推挽输出驱动蜂鸣器 */
    GPIO_InitTypeDef gpio;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Pin = GPIO_Pin_12;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &gpio);

    while (1)
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_12); // 蜂鸣器鸣叫
        Delay_ms(200);
        GPIO_SetBits(GPIOB, GPIO_Pin_12);   // 蜂鸣器静音
        Delay_ms(800);
    }
}



