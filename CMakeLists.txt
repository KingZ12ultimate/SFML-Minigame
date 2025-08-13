cmake_minimum_required(VERSION 3.28)
project(SFML-Minigame LANGUAGES CXX)

# Set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Require C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Fetch SFML from GitHub
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

# Collect all cpp files in src/ folder automatically
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Use those files in your executable target
add_executable(App ${SRC_FILES})

# Or if you already have a target, use:
# target_sources(App PRIVATE ${SRC_FILES})

# Link all SFML modules
target_link_libraries(App PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Window
    SFML::System
    SFML::Network
)


# -------------------------------------------------
# Copy SFML DLLs to the runtime folder automatically
# -------------------------------------------------
add_custom_command(TARGET App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<TARGET_FILE_DIR:SFML::Graphics>"
        "$<TARGET_FILE_DIR:App>"
)
