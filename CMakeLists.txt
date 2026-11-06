cmake_minimum_required(VERSION 3.21)
project(sdl_painter_starter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(sdl_painter CONFIG REQUIRED)

add_executable(starter src/main.cpp)

# sdl_painter::app is the optional window/event-loop layer; it brings
# sdl_painter::sdl_painter (the drawing library) with it.
target_link_libraries(starter PRIVATE sdl_painter::app)

if(MSVC)
    target_compile_options(starter PRIVATE /W4 /utf-8)
else()
    target_compile_options(starter PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Windows: copy the DLLs the program links against next to the executable, so
# it starts from the build directory. With the default static packages the list
# is empty and nothing is copied.
if(WIN32)
    add_custom_command(TARGET starter POST_BUILD
        COMMAND "$<$<BOOL:$<TARGET_RUNTIME_DLLS:starter>>:${CMAKE_COMMAND};-E;copy_if_different;$<TARGET_RUNTIME_DLLS:starter>;$<TARGET_FILE_DIR:starter>>"
        COMMAND_EXPAND_LISTS
        VERBATIM)
endif()
