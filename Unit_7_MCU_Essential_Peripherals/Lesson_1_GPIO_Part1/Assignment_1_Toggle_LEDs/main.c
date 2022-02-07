/*
 * Unit_7_Lesson_1_Assignment_1.c
 *
 * Created: 2/7/2022 9:42:30 PM
 * Author : Mina Karam
 */ 

typedef volatile unsigned char vuint8_t;
typedef unsigned int uint32_t;

// GPIO
#define GPIO_BASE   0x20
#define DDRC        (*(vuint8_t *)(GPIO_BASE + 0x14))
#define PORTC       (*(vuint8_t *)(GPIO_BASE + 0x15))

// GPIO pins
#define PC0     0
#define PC1     1
#define PC2     2
#define PC3     3

// Hardware pins
#define LED0    PC0
#define LED1    PC1
#define LED2    PC2
#define BUZZER  PC3

// Utilities 
#define SET_BIT(reg, bit)   (reg |= (1<<bit))
#define CLR_BIT(reg, bit)   (reg &= ~(1 << (bit)))

// Prototypes
void delay(uint32_t count);

int main(void)
{
    // Initialize Port C pins as output related to hardware pins
    DDRC |= (1 << LED0)|(1 << LED1)|(1 << LED2)|(1 << BUZZER);
    
    while (1)
    {
        // First Stage
        CLR_BIT(PORTC, BUZZER);     // Clear BUZZER
        CLR_BIT(PORTC, LED2);       // Clear LED2
        CLR_BIT(PORTC, LED1);       // Clear LED1
        SET_BIT(PORTC, LED0);       // Set LED0
        delay(1000);
        
        // Second Stage
        CLR_BIT(PORTC, LED0);       // Clear LED0
        SET_BIT(PORTC, LED1);       // Set LED1
        delay(1000);
        
        // Third Stage 
        CLR_BIT(PORTC, LED1);       // Clear LED1
        SET_BIT(PORTC, LED2);       // Set LED2
        delay(1000);
        
        // Forth Stage
        SET_BIT(PORTC, BUZZER);     // Set BUZZER
        delay(1000);
    }
    return 0;
}


void delay(uint32_t count)
{
    vuint8_t i;
    
    while(count--)
    {
        for(i = 0; i < 255; i++);
    }
}