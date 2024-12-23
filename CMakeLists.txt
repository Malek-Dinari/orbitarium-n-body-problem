# CMakeLists.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Project name and C++ standard configuration
project(orbitarium-n-body-problem VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include SFML manually from C:/SFML
include_directories("C:/SFML/include")
link_directories("C:/SFML/lib")

find_package(SFML 3 COMPONENTS graphics window system "C:/SFML")

# Add the executable target
add_executable(${PROJECT_NAME})

# Add source files (better to list explicitly for larger projects)
target_sources(${PROJECT_NAME}
    PRIVATE
    src/Simulation.cpp
    src/main.cpp  # Main file
    src/nbody.cpp
)

# Set SFML directory
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

# Include directories for project headers
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-main-s # For Windows GUI
)

# Copy SFML DLLs to the build directory (important for runtime)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "C:/SFML/bin/sfml-graphics-3.dll"
    "C:/SFML/bin/sfml-window-3.dll"
    "C:/SFML/bin/sfml-system-3.dll"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
)
