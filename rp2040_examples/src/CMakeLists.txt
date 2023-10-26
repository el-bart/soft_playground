cmake_minimum_required(VERSION 3.12)

set(PICO_CXX_ENABLE_EXCEPTIONS true) # exceptions are off by default

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
# ^^ is effectively vv
#set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
#include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(pico_blink C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall)
# LTO does not seem to be operational atm
#add_compile_options(-flto)


function(add_binary name)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} pico_stdlib)
  # create map/bin/hex/uf2 file etc.
  pico_add_extra_outputs(${name})
endfunction()

add_binary(blink)

add_binary(cpp_tour_blink)

add_binary(cpp_serial)

add_binary(pwm_dual_servo)
target_link_libraries(pwm_dual_servo hardware_pwm)
