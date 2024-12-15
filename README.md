# Hotel Management System

## Overview
This project is a hotel management application developed in C++. It allows for the management of hotel rooms, clients, and reservations. The application provides functionalities to handle client data, room information, and reservation processes.

## Project Structure
```
hotel-management
├── src
│   ├── main.cpp          # Entry point of the application
│   ├── client.cpp        # Implementation of the Client class
│   ├── client.h          # Header file for the Client class
│   ├── chambre.cpp       # Implementation of the Chambre class
│   ├── chambre.h         # Header file for the Chambre class
│   ├── reservation.cpp    # Implementation of the Reservation class
│   ├── reservation.h      # Header file for the Reservation class
├── CMakeLists.txt        # CMake configuration file
└── README.md             # Project documentation
```

## Setup Instructions
1. Clone the repository:
   ```
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```
   cd hotel-management
   ```
3. Create a build directory and navigate into it:
   ```
   mkdir build && cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   make
   ```

## Usage
- Run the application from the build directory:
  ```
  ./hotel-management
  ```
- Follow the on-screen instructions to manage clients, rooms, and reservations.

## Additional Information
This application is designed to handle up to 80 rooms and includes features for checking room availability, managing client information, and processing reservations. Each class is implemented with methods for input, output, and data management as per the project specifications.