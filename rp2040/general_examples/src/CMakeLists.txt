cmake_minimum_required(VERSION 3.12)

set(PICO_CXX_ENABLE_EXCEPTIONS true) # exceptions are off by default

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
# ^^ is effectively vv
#set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
#include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(pico_blink C CXX ASM)

#set(PICO_BOARD pico)
set(PICO_BOARD pico_w)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.1")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.1 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall)
# LTO does not seem to be operational atm
#add_compile_options(-flto)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")


function(add_binary name)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} pico_stdlib)
  # create map/bin/hex/uf2 file etc.
  pico_add_extra_outputs(${name})
endfunction()

if ("${PICO_BOARD}" MATCHES "^pico_w$")
  message("PICO W does not have LED in usual spot - skipping these examples")
else()
  message("PICO non-W - building LED apps")
  add_binary(blink)
  add_binary(cpp_tour_blink)
endif()

add_binary(cpp_serial)

add_binary(cpp_json_format)
target_include_directories(cpp_json_format SYSTEM PRIVATE .)
pico_enable_stdio_uart(cpp_json_format ENABLED)

add_binary(pwm_dual_servo)
target_link_libraries(pwm_dual_servo hardware_pwm)

if ("${PICO_BOARD}" MATCHES "^pico_w$")
  add_compile_options(-DCYW43_LWIP=0)
  add_compile_options(-DENABLE_CLASSIC=0)
  add_compile_options(-DLIB_PICO_ASYNC_CONTEXT_THREADSAFE_BACKGROUND=1)
  add_compile_options(-DLIB_PICO_BTSTACK_CLASSIC=0)
  add_compile_options(-DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1)
  add_compile_options(-DPICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS=3000)
  add_binary(cpp_btle)
  target_link_libraries(cpp_btle pico_btstack_cyw43 pico_btstack_ble)
else()
  message("PICO does not have BTLE - skipping these examples")
endif()
