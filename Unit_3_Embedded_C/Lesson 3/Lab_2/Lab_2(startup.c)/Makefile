#@CopyRight at Mina Karam
#@Description : This is the generic makefile for arm32 projects

CC     =arm-none-eabi-
CFLAGS =-mcpu=cortex-m3 -gdwarf-2
LIBS   =
SRC    =$(wildcard *.c)
OBJ    =$(SRC:.c=.o)# same as OBJS = $(patsubst %.c,%.o,$SRC)
ASM    =$(wildcard *.s)
ASMOBJ =$(ASM:.s=.o)
LINKER =$(wildcard *.ld)
Project_Name =Embedded_C_Lesson_3_Lab_2

All: $(Project_Name).bin
	@echo "============== Build is Done ============="
	
%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_Name).elf: $(OBJ) $(ASMOBJ)
	$(CC)ld.exe -T $(LINKER) $(INCS) $(OBJ) -Map=Map_File.map -o $@ 

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *elf *.bin
	@echo "============== Everything Clean ============="

clean:
	rm *.elf *.bin