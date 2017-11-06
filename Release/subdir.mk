################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\AP_Service.cpp \
..\wifi_color_light.cpp 

LINK_OBJ += \
.\AP_Service.cpp.o \
.\wifi_color_light.cpp.o 

CPP_DEPS += \
.\AP_Service.cpp.d \
.\wifi_color_light.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
AP_Service.cpp.o: ..\AP_Service.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"F:\cpp-oxygen\/arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IF:\cpp-oxygen\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.3.0/tools/sdk/include" "-IF:\cpp-oxygen\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.3.0/tools/sdk/lwip/include" "-IG:\eclipse-workspace\wifi_color_light/Release/core" -c -Wall -Wextra -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_WEMOS_D1MINI\"" -DESP8266  -I"F:\cpp-oxygen\arduinoPlugin\packages\esp8266\hardware\esp8266\2.3.0\cores\esp8266" -I"F:\cpp-oxygen\arduinoPlugin\packages\esp8266\hardware\esp8266\2.3.0\variants\d1" -I"G:\eclipse-workspace\wifi_color_light\ESP8266WiFi\src" -I"G:\eclipse-workspace\wifi_color_light\EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

wifi_color_light.cpp.o: ..\wifi_color_light.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"F:\cpp-oxygen\/arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IF:\cpp-oxygen\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.3.0/tools/sdk/include" "-IF:\cpp-oxygen\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.3.0/tools/sdk/lwip/include" "-IG:\eclipse-workspace\wifi_color_light/Release/core" -c -Wall -Wextra -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC  -DARDUINO=10802 -DARDUINO_ESP8266_WEMOS_D1MINI -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_WEMOS_D1MINI\"" -DESP8266  -I"F:\cpp-oxygen\arduinoPlugin\packages\esp8266\hardware\esp8266\2.3.0\cores\esp8266" -I"F:\cpp-oxygen\arduinoPlugin\packages\esp8266\hardware\esp8266\2.3.0\variants\d1" -I"G:\eclipse-workspace\wifi_color_light\ESP8266WiFi\src" -I"G:\eclipse-workspace\wifi_color_light\EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


