# MCU name
MCU = STM32F072
DFU_ARGS = -d 0483:df11 -a 0 -s 0x08000000:leave

# Build Options
#   comment out to disable the options.
#

#BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = no	# Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	# USB Nkey Rollover

DEFAULT_FOLDER = pulsar/rev2

ENCODER_ENABLE = yes
EXTRAFLAGS += -flto
RGBLIGHT_ENABLE = yes  # Enable keyboard RGB underglow
SLEEP_LED_ENABLE = yes # Breathing sleep LED during USB suspend
