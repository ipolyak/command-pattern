cmake_minimum_required(VERSION 3.0.2)

set(PROJECT_NAME command-pattern)
project(${PROJECT_NAME})

# Choose Debug/Release mode
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

# Set compiler flags
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

set(CXX_STANDARD 98)
set(CXX_STANDARD_REQUIRED ON)

# Build
# - command library
set(COMMAND_LIBRARY "command-lib")
set(COMMAND_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/command/include")


# - libraries
add_subdirectory("command/src")

# - application
add_subdirectory("application")

# Report
message(STATUS "")
message(STATUS "==============================================================")
message(STATUS "Configuration for ${PROJECT_NAME}")
message(STATUS "==============================================================")
message(STATUS "")
message(STATUS "Configuration: ${CMAKE_BUILD_TYPE}")
message(STATUS "Include directories:")
message(STATUS "   - ${COMMAND_LIBRARY}: ${COMMAND_INCLUDE_DIR}")
message(STATUS "Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}")
message(STATUS "")
message(STATUS "==============================================================")
message(STATUS "")
