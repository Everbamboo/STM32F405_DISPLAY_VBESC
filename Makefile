# VESC风格Makefile示例
PROJECT = STM32F405_DISPLAY_VBESC
MCU = STM32F405RG
BUILD_DIR = build

# 源文件收集
SRCS = \
  core/main.c \
  board/board.c \
  drivers/display_ili9225.c \
  drivers/input.c \
  drivers/buzzer_led.c \
  protocol/vesc_uart.c \
  ui/ui_manager.c \
  storage/data_store.c \
  utils/syscalls.c

STARTUP = startup_stm32f405xx.s

# 头文件路径
INCLUDES = \
  -Icore \
  -Iboard \
  -Idrivers \
  -Iprotocol \
  -Iui \
  -Istorage

# 工具链
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -O2 -Wall $(INCLUDES)
LDFLAGS = -TSTM32F405RG_FLASH.ld


all: | $(BUILD_DIR)
all: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(PROJECT).elf: $(SRCS) $(STARTUP)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT).elf
	$(OBJCOPY) -O binary $^ $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
