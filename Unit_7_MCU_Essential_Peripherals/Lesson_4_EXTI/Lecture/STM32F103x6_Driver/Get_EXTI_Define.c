#include "stdio.h"

void main(void)
{
	for (int i = 0; i < 16; ++i)
	{
		printf("\n\n//EXTI%d \n",i);
		printf("#define EXTI%dPA%d	(EXTI_GPIO_Mapping_t){EXTI%d, GPIOA, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,i,i,i,i);
		printf("#define EXTI%dPB%d	(EXTI_GPIO_Mapping_t){EXTI%d, GPIOB, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,i,i,i,i);
		printf("#define EXTI%dPC%d	(EXTI_GPIO_Mapping_t){EXTI%d, GPIOC, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,i,i,i,i);
		printf("#define EXTI%dPD%d	(EXTI_GPIO_Mapping_t){EXTI%d, GPIOD, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,i,i,i,i);
	}
}