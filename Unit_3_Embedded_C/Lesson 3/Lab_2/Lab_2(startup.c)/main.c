/*	main.c
*
*	CopyRight : Mina Karam	
*/


#include "Platform_Types.h"

/* register address */
#define RCC_BASE 			0x40021000
#define GPIOA_BASE 			0x40010800

#define RCC_APB2ENR 		*((vuint32_t*) (RCC_BASE + 0x18))
#define GPIOA_CRH 			*((vuint32_t*) (GPIOA_BASE + 0x04))
#define GPIOA_ODR 			*((vuint32_t*) (GPIOA_BASE + 0x0C))

/* bit fields*/
typedef union {
	vuint32_t All_Fields;
	struct {
		vuint32_t reserved:13;
		vuint32_t p_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

#define RCC_IOPAEN	(1<<2)
#define GPIOA_Pin13	(1UL<<13)

uint32_t global_variables[3] = {1,2,3};
uint32_t const const_variavles [3] = {1,2,3};

extern void NMI_Handler(void)
{

}

extern void Bus_Fault(void)
{

}

int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN; // Enable clock rcc
	GPIOA_CRH &= 0xff0fffff; // get them 0 first before change it
	GPIOA_CRH |= 0x00200000; // now we can set 2 safely

	while(1)
	{
//		GPIOA_ODR |= GPIOA_Pin13 ; // Set port a pin 13
		R_ODR->pin.p_13 = 1;
		for(int i = 0 ;i < 500 ; i++);

//		GPIOA_ODR &= ~(GPIOA_Pin13) ; // Clear port a pin 13
		R_ODR->pin.p_13 = 0;
		for(int i = 0 ;i < 500 ; i++);
	}

	return 0;
}
