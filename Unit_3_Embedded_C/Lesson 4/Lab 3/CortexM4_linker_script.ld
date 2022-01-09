/* arm cortex-m3 linker script
Made by Mina Karam
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M 	/* 0.5 GB*/
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M	/* 0.5 GB*/
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_TEXT = . ;
	}>flash

	.data : {
		_S_DATA = . ;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = . ;
	}>sram AT>flash
	
	.bss : {
		_S_BSS = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = . ;
	}>sram
}
