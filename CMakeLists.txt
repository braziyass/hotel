cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HotelManagement)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(HotelManagement
    src/main.cpp
    src/client.cpp
    src/chambre.cpp
    src/reservation.cpp
)

# Include directories
include_directories(src)