/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina Karam
 * @brief          : Control LEDs using push buttons on STM32F103C6
 ******************************************************************************
 */

typedef volatile unsigned int vuint32_t ;

// GPIO
#define GPIOA_BASE 0x40010800
#define GPIOA_CRL   *((vuint32_t*)(GPIOA_BASE+0x00))
#define GPIOA_CRH   *((vuint32_t*)(GPIOA_BASE+0x04))
#define GPIOA_IDR   *((vuint32_t*)(GPIOA_BASE+0x08))
#define GPIOA_ODR   *((vuint32_t*)(GPIOA_BASE+0x0C))

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRL   *((vuint32_t*)(GPIOB_BASE+0x00))
#define GPIOB_CRH   *((vuint32_t*)(GPIOB_BASE+0x04))
#define GPIOB_IDR   *((vuint32_t*)(GPIOB_BASE+0x08))
#define GPIOB_ODR   *((vuint32_t*)(GPIOB_BASE+0x0C))

// RCC
#define RCC_BASE    0x40021000
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0x18)

void clock_init (void)
{
    RCC_APB2ENR |= (1 << 2);                // Enable clock for PORT A
    RCC_APB2ENR |= (1 << 3);                // Enable clock for PORT B
}

void GPIO_init (void)
{
    // Configure PA1 as input floating
    GPIOA_CRL |= (0b0100 << 4);

    // Configure PA13 as input floating
    GPIOA_CRH |= (0b0100 << 20);

    // Configure PB1 as output push-pull
    GPIOB_CRL &= ~(0b1111 << 4);                // clear all 4 mode and config bits
    GPIOB_CRL |= (0b0001 << 4);

    // Configure PB13 as output push-pull
    GPIOB_CRH &= ~(0b1111 << 20);                // clear all 4 mode and config bits
    GPIOB_CRH |= (0b0001 << 20);

}

int main(void)
{
    clock_init();
    GPIO_init();

    int delay = 0;

    GPIOB_ODR |= (1 << 1);                      // LED 1 initially OFF
    GPIOB_ODR |= (1 << 13);                     // LED 2 initially OFF

    while (1)
    {
        if (((GPIOA_IDR & (1 << 1)) >> 1) == 0)
        {
            GPIOB_ODR ^= (1 << 1);              // Toggle LED on PB1
            while (((GPIOA_IDR & (1 << 1)) >> 1) == 0);
        }

        if (((GPIOA_IDR & (1 << 13)) >> 13) == 1)
        {
            GPIOB_ODR ^= (1 << 13);                 // Toggle LED on PB13
            for (delay = 0 ; delay < 10000 ; delay ++);
        }
    }
}
