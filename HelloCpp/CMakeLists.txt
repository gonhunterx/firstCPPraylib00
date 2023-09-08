cmake_minimum_required(VERSION 3.15)

project(hellocpp CXX)

# Set C++20 standard flag on the compiler (among C++03, C++11, C++14, C++17, C++20, C++23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# External dependencies
#
# Many projects support CMake. They can be integrated into your CMake project.
# 
# You can go on GitHub, see if one of the libraries you are interested in 
# has a CMakeLists.txt file at the root of the repository. If so, go to the
# releases page and see the latest stable release, at the bottom of it, you 
# can see download links to the sources "Source code (zip)" or 
# "Source code (tar.gz)". Use preferably (tar.gz) as they are smaller in size.
# Copy the download link and paste it here, the same way it is done in the
# examples below.

include(FetchContent)

# spdlog https://github.com/gabime/spdlog
# 
# allows you to easily write log messages (in files, in the console, 
# etc.) with different log levels (debug, info, error, warning, etc.) and 
# timestamps.
FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/refs/tags/v1.11.0.tar.gz)

# GSL https://github.com/microsoft/GSL
# 
# The Guidelines Support Library (GSL) contains functions and types that
# are suggested for use by the C++ Core Guidelines maintained by the Standard 
# C++ Foundation
# FetchContent_Declare(gsl URL https://github.com/microsoft/GSL/archive/refs/tags/v4.0.0.tar.gz)

# JSON https://github.com/nlohmann/json
# 
# JSON for Modern C++
# FetchContent_Declare(json URL https://github.com/nlohmann/json/archive/refs/tags/v3.11.2.tar.gz)

# Here list the names of the dependencies you mentioned before with the FetchContent_Declare() function
# This is a space separated list, e.g.: spdlog gsl json

FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.5.0.tar.gz)




FetchContent_MakeAvailable(spdlog PRIVATE raylib)

# List your sources recursively from the src/ directory
file(GLOB_RECURSE HELLOCPP_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Make your executable out of all the sources
add_executable(hellocpp ${HELLOCPP_SOURCE_FILES})

# Link external dependencies against your executable
# 
# The way you have to refer to the libraries can be different depending 
# on the library. See the README.md of each dependency repository to know 
# more on how to link it to your executable

# spdlog
target_link_libraries(hellocpp PRIVATE spdlog::spdlog)
# You can uncomment the next line if you want to use all the log levels when using macros
target_compile_definitions(hellocpp PRIVATE SPDLOG_ACTIVE_LEVEL=0)

# GSL
# target_link_libraries(hellocpp PRIVATE Microsoft.GSL::GSL)

# JSON
# target_link_libraries(hellocpp PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries(hellocpp raylib)