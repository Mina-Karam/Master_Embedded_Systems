# Makefile
#@CopyRight at Mina Karam
#@Description : This is the generic makefile for arm32 projects


# Directories
# Source Directories
SRC_DIR = src
# Include directories
INC_DIR = inc
# Assembly Directories
ASM_DIR = asm
# Dependecies directories
DEP_DIR = dependencies
# Object directories
OBJ_DIR = obj
# App directories
APP_DIR = app
# Binaries directories
BIN_DIR = bin
# Source Dump Directories
SRC_DUMP_DIR = src

# File names
# C Source Files
SRC = $(wildcard $(SRC_DIR)/*.c $(APP_DIR)/*.c)
# Assembly source files
ASM = $(wildcard $(ASM_DIR)/*.s)
# Object files from C files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# Object files from assembly files
ASM_OBJ = $(ASM:$(ASM_DIR)/%.s=$(OBJ_DIR)/%.o)
# Dependcies for each source (prerequisites)
DEP = $(SRC:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)
# Target
TARGET = $(BIN_DIR)/P1_Pressure_Controller
######################################

# Architecture-specific
# Linker script
LINKER_FILE = linker_script.ld
# Map file
MAP_FILE = $(BIN_DIR)/map_file.map
# Processor name
CPU = cortex-m3
# ARM-specific flags
ARM_CFLAGS = -mcpu=$(CPU)
######################################

# Compiler tools
# Compiler
CC = arm-none-eabi-gcc
# Assembler
AS = arm-none-eabi-as
# Linker
LD = arm-none-eabi-ld
# Object copy utility
OBJCOPY = arm-none-eabi-objcopy
######################################

# Compiler flags
CFLAGS = $(ARM_CFLAGS) -c $(DEBUG_OPTIONS)
# Preprocessor flags
CPPFLAGS = -I$(INC_DIR) $(DEPFLAGS)
# Assembler flags
ASFLAGS = $(ARM_CFLAGS) $(DEBUG_OPTIONS)
# Linker flags
LDFLAGS = -T $(LINKER_FILE) -Map=$(MAP_FILE)
# Dependency flags (belongs to CPPFLAGS)
DEPFLAGS = -MMD -MP -MF $(<:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)
# Debug flags
DEBUG_OPTIONS = -gdwarf-2 -g
######################################

# Cppcheck variables
SRC_DUMP = $(SRC:$(SRC_DIR)/%.c=$(SRC_DUMP_DIR)/%.c.dump)
CPPCHECK_PATH := $(shell dirname -- "$(shell which cppcheck)")
MISRA_PATH = "$(CPPCHECK_PATH)/addons/misra.py"
######################################

# Make rules (targets)
.PHONY: all
all: $(TARGET).bin
	@echo ""
	@echo "=======Build is Successful======="
######################################

# Generate binary image from elf image
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
######################################

# Generate output executable from object files
$(TARGET).elf: $(OBJ) $(ASM_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^
	cp $@ $(TARGET).axf
######################################

# Generate object file from assembly file
$(OBJ_DIR)/%.o: $(ASM_DIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<
######################################

# Generate object file from c file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<
######################################

# Clean target files
.PHONY: clean
clean:
	rm -rf $(TARGET).* $(MAP_FILE)
	@echo ""
	@echo "=======Build is Ready for Re-Linking========"
######################################

# Clean project from generated files
.PHONY: clean_all
clean_all:
	rm -rf $(TARGET).* $(OBJ) $(DEP) $(MAP_FILE) $(SRC_DUMP)
	@echo ""
	@echo "=======Build is Clean========"
######################################

# Include dependencies to source files
# - means to suppress the error at first
-include $(DEP)
######################################

# Misra compliancy check
.PHONY: misra_compliancy
misra_compliancy: $(SRC_DUMP)
	-python $(MISRA_PATH) $^
	@echo ""
	@echo "=======Misra Compliancy Check is Done========"
######################################

# Generate dump file from c file
$(SRC_DUMP_DIR)/%.c.dump: $(SRC_DIR)/%.c
	cppcheck --dump -I $(INC_DIR) $<
######################################
