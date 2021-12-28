#create preprocessed files
arm-none-eabi-gcc.exe -E app.c -o app.i
arm-none-eabi-gcc.exe -E uart.c -o uart.i

#define Compiler and Assembler flags
GCC_Flags="-mcpu=arm926ej-s -c -I. "
ASM_Flags="-mcpu=arm926ej-s "

#create object files
arm-none-eabi-gcc.exe $GCC_Flags app.c -o app.o
arm-none-eabi-gcc.exe $GCC_Flags uart.c -o uart.o
arm-none-eabi-as.exe $ASM_Flags startup.s -o startup.o

#create objdump files
arm-none-eabi-objdump.exe -h -D app.o > app.s
arm-none-eabi-objdump.exe -h -D uart.o > uart.s
arm-none-eabi-objdump.exe -h -D startup.o > start.s

#extract the symbol table of each object
arm-none-eabi-nm.exe app.o > appSTable.txt
arm-none-eabi-nm.exe uart.o > uartSTable.txt
arm-none-eabi-nm.exe startup.o > startupSTable.txt

#link and produce the map file
arm-none-eabi-ld.exe -T -Map=map_file.map Linker_Script.ld startup.o app.o uart.o -o Mina.elf

#convert elf to bin file
arm-none-eabi-objcopy.exe -O binary Mina.elf Mina.bin

#run the simulation
qemu-system-arm.exe -M versatilepb -m 128M -nographic -kernel Mina.bin