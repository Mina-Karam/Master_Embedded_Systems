/*	Cortex-M4_startup.c
*
*	CopyRight : Mina Karam	
*/

#include "Platform_Types.h"

void Reset_Hundler(void);

extern int main(void);

void Default_Hundler()
{
	Reset_Hundler();
}

void NMI_Handler(void)				__attribute__ ((weak, alias("Default_Hundler")));;
void H_Fault_Handler(void)			__attribute__ ((weak, alias("Default_Hundler")));;
void MM_Fault_Handler(void)			__attribute__ ((weak, alias("Default_Hundler")));;
void Bus_Fault(void)				__attribute__ ((weak, alias("Default_Hundler")));;
void Usage_Fault_Handler(void)		__attribute__ ((weak, alias("Default_Hundler")));;

//extern uint32_t _STACK_TOP ;
//booking 1024 B located by .bss through uninitalized array of int 256 Element (256*4 = 1024)
//reserve static size 
static uint32_t Stack_Top[256];
/* Stack_Top is included in .bss section as shown below the size of 
   is 0x400 = 1024 B and then specify the stack_top + <size> to SP register
   ((all of this explained in arm-none-eabi-nm.exe file.elf))*/


/*uint32_t vectors[] __attribute__ ((section(".vectors"))) = {
	(uint32_t)	(&Stack_Top[0] + sizeof(Stack_Top)),
	(uint32_t)	&Reset_Hundler,
	(uint32_t)	&NMI_Handler,
	(uint32_t)	&H_Fault_Handler,
	(uint32_t)	&MM_Fault_Handler,
	(uint32_t)	&Bus_Fault,
	(uint32_t)	&Usage_Fault_Handler
};*/

void (*const g_p_fn_vectors[])() __attribute__ ((section(".vectors"))) =
{
	(void(*)())	((uint32_t)Stack_Top + sizeof(Stack_Top)),
	&Reset_Hundler, // Vectors section is an array of pointer to function
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler

}; // don't forget ";"

extern uint32_t _E_TEXT ;
extern uint32_t _S_DATA ;
extern uint32_t _E_DATA ;
extern uint32_t _S_BSS ;
extern uint32_t _E_BSS ;

void Reset_Hundler (void)
{
	//copy data from ROM to RAM
	uint32_t DATA_Size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA ;
	uint8_t* P_src = (uint8_t*)&_E_TEXT ;
	uint8_t* P_dst = (uint8_t*)&_S_DATA ;
	
	for (int i = 0; i < DATA_Size; ++i)
		{
			*((uint8_t*)P_dst++) = *((uint8_t*)P_src++) ; 
		}

	// init the .bss with zero
	uint32_t BSS_Size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS ;
	P_dst = (uint8_t*)&_S_BSS ;

	for (int i = 0; i < BSS_Size; ++i)
		{
			*((uint8_t*)P_dst++) = (uint8_t)0 ; 
		}

	//jump to main 
	main();
}