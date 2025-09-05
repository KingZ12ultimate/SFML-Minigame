cmake_minimum_required(VERSION 3.28)
project(SFML-Minigame LANGUAGES CXX)

# Set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Require C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMP0167 NEW)

# Fetch Dependencies from GitHub (e.g. SFML, Boost::optional, etc.)
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

#FetchContent_Declare(
#    Boost
#    URL https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.zip
#    URL_MD5 2b36c6002d2a35eac3e6cb07c0097f77
#    DOWNLOAD_EXTRACT_TIMESTAMP ON
#    EXCLUDE_FROM_ALL
#)
#FetchContent_Declare(
#    Boost
#    GIT_REPOSITORY https://github.com/boostorg/boost.git
#    GIT_TAG boost-1.89.0
#    GIT_SHALLOW ON
#    EXCLUDE_FROM_ALL
#)
#FetchContent_MakeAvailable(Boost)

# Collect all source and header files in src/ folder automatically
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.hpp" "src/*.h")

add_executable(App ${SRC_FILES} ${HEADER_FILES})

# Organize them in Visual Studio filters
source_group("Source Files" FILES ${SRC_FILES})
source_group("Header Files" FILES ${HEADER_FILES})

# Link all SFML modules
target_link_libraries(App PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Window
    SFML::System
    SFML::Network
#    Boost::optional
)

# -------------------------------------------------
# Copy SFML DLLs to the runtime folder automatically
# -------------------------------------------------
add_custom_command(TARGET App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<TARGET_FILE_DIR:SFML::Graphics>"
        "$<TARGET_FILE_DIR:App>"
)
