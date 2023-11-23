cmake_minimum_required(VERSION 3.25.1)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(${PROJECT_NAME}
    main.cpp
    src/rpp.cpp
    src/rpp.h
    src/stepper.cpp
    src/stepper.h
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${PROJECT_NAME})