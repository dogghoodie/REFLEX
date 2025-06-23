cmake_minimum_required(VERSION 3.10)
project(REFLEX LANGUAGES CXX)

# Enable compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binary to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Include headers
include_directories(${PROJECT_SOURCE_DIR}/src/include)

# ADD EXECUTABLE BEFORE LINKING LIBRARIES!
add_executable(REFLEX
    src/cpp/main.cpp
    src/cpp/progress_bar.cpp
    src/cpp/reflex.cpp
)

# Link ncurses after target is created
target_link_libraries(REFLEX ncurses)
