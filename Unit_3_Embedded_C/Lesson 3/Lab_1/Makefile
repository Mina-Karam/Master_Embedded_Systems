#@CopyRight at Mina Karam
#@Description : This is the generic makefile for arm32 projects

CC     =arm-none-eabi-
CFLAGS =-mcpu=arm926ej-s -g
INCS   =-I .
LIBS   =
SRC    =$(wildcard *.c)
OBJ    =$(SRC:.c=.o)# same as OBJS = $(patsubst %.c,%.o,$SRC)
ASM    =$(wildcard *.s)
ASMOBJ =$(ASM:.s=.o)
Project_Name =Mina

All: $(Project_Name).bin
	@echo "============== Build is Done ============="
	
%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_Name).elf: $(OBJ) $(ASMOBJ)
	$(CC)ld.exe -T Linker_Script.ld $(INCS) $(OBJ) -Map=Map_File.map -o $@ 

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *elf *.bin
	@echo "============== Everything Clean ============="

clean:
	rm *.elf *.bin