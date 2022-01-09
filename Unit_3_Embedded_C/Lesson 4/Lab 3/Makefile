#@CopyRight at Mina Karam
#@Description : This is the generic makefile for arm32 projects

CC     =arm-none-eabi-
CFLAGS =-mcpu=cortex-m4 -gdwarf-2 -g
INCS   =-I .
LIBS   =
SRC    =$(wildcard *.c)
OBJ    =$(SRC:.c=.o)# same as OBJS = $(patsubst %.c,%.o,$SRC)
ASM    =$(wildcard *.s)
ASMOBJ =$(ASM:.s=.o)
LINKER =$(wildcard *.ld)
Project_Name =Embedded_C_Lesson_4_Lab_3

All: $(Project_Name).bin
	@echo "============== Build is Done ============="
	
%.o: %.s
	$(CC)as.exe  $(CFLAGS) $(INCS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_Name).elf: $(OBJ) $(ASMOBJ)
	$(CC)ld.exe -T $(LINKER) $(LIBS) $(OBJ) $(ASMOBJ) -Map=Map_File.map -o $@ 
	cp $(Project_Name).elf $(Project_Name).axf

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.axf *.bin
	@echo "============== Everything Clean ============="

clean:
	rm *.elf *.bin