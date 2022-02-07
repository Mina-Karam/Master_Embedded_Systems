/*
 * Unit_6_Lesson_4_Lab_3.c
 *
 * Created: 2/7/2022 12:43:07 AM
 * Author : Mina Karam
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

void GPIO_init(void);
void EXTI_init(void);

int main(void)
{
    // Initialize GPIO LEDs pin
    GPIO_init();
    
    // Initialize external interrupt
    EXTI_init();
    
    while (1) 
    {
        // Turn off all LEDs
        PORTD &= ~((1<<PD5)|(1<<PD6)|(1<<PD7));
    }
    return 0;
}

ISR(INT0_vect)
{
    // Turn led on
    PORTD |= (1<<PD5);
    
    // Wait 1 second 
    _delay_ms(1000);
    
    // Turn led off
    PORTD &= (~1<<PD5);
}

ISR(INT1_vect)
{
    // Turn led on
    PORTD |= (1<<PD6);
        
    // Wait 1 second
    _delay_ms(1000);    
    
    // Turn led off
    PORTD &= (~1<<PD6);
}

ISR(INT2_vect)
{
    // Turn led on
    PORTD |= (1<<PD7);
        
    // Wait 1 second
    _delay_ms(1000);
    
    // Turn led off
    PORTD &= (~1<<PD7);
}
void GPIO_init(void)
{
    // Port D set direction to output
    DDRD |= (1<<PD5)|(1<<PD6)|(1<<PD7);
}

void EXTI_init(void)
{
    // Global interrupt enable 
    sei();
        
    // Configuration of MCU Control Register to interrupt sense
    // INT0 -> Any logical change
    // INT1 -> Rising edge
    // INT2 -> Falling edge
    MCUCR |= (1 << ISC11) | (1 << ISC10) | (1 << ISC00);
    
    // External Interrupt Request Enable
    GICR |= (1<<INT1)|(1<<INT0)|(1<<INT2);
}