/*
 * Unit_7_Section_1_Task_2.c
 *
 * Created: 2/8/2022 00:47:50 AM
 * Author : Mina Karam
 */ 

typedef volatile unsigned char vuint8_t;
typedef unsigned int uint32_t;

// GPIO
#define GPIO_BASE   0x20

//GPIO PORTA registers
#define PORTA   *(vuint8_t *)(GPIO_BASE + 0x1B) //PORTA data register
#define DDRA    *(vuint8_t *)(GPIO_BASE + 0x1A) //PORTA data direction register
#define PINA    *(vuint8_t *)(GPIO_BASE + 0x19) //PORTA data input register

//GPIO PORTC registers
#define PORTC   *(vuint8_t *)(GPIO_BASE + 0x15) //PORTC data register
#define DDRC    *(vuint8_t *)(GPIO_BASE + 0x14) //PORTC data direction register
#define PINC    *(vuint8_t *)(GPIO_BASE + 0x13) //PORTC data input register

// GPIO PORTA pins
#define PA0     0
#define PA1     1
#define PA2     2
#define PA3     3
#define PA4     4
#define PA5     5
#define PA6     6
#define PA7     7

// GPIO PORTA pins
#define PC0     0

// Hardware pins
#define LED0    PA0
#define LED1    PA1
#define LED2    PA2
#define LED3    PA3
#define LED4    PA4
#define LED5    PA5
#define LED6    PA6
#define LED7    PA7

#define SWitch  PC0

// Utilities 
#define SET_BIT(reg, bit)       (reg |= (1<<bit))
#define CLR_BIT(reg, bit)       (reg &= ~(1 << (bit)))
#define GET_BIT(reg, bit)       (((reg)>>(bit))&1)
#define TOGGLE_BIT(reg, bit)    (reg^=(1<<bit))

// Prototypes
void delay(uint32_t count);

int main(void)
{
    // Initialize Port A pins as output related to hardware pins
    DDRA = 0xFF;  
    
    while(1)
    {
        if (GET_BIT(PINC, SWitch) == 1)
        {
            do 
            {
                uint32_t i;
                
                for(i = 0; i <= 7; i++)
                {
                    //Turn ON LED Sequentially
                    SET_BIT(PORTA, i);
                    
                    delay(100); //delay
                }
                
                for(i = 7;i >= 0; i--)
                {
                    //Turn OFF LED Sequentially
                    CLR_BIT(PORTA, i);
                    
                    delay(100); //delay
                }
            } while (GET_BIT(PINC, SWitch) == 1);
        }
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