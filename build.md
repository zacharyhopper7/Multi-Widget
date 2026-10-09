# Building and Running the Qt To-Do List Application

This document provides step-by-step instructions for building and running the Qt To-Do List application.

## Prerequisites

Before building the application, ensure you have the following installed:

### Required Software

- **CMake** (version 3.16 or higher)
- **Qt6** with Widgets component
- **C++ Compiler** with C++17 support (GCC, Clang, or MSVC)
- **Make** or **Ninja** build system

### Installing Prerequisites on macOS

Using Homebrew (recommended):

```bash
# Install Qt6
brew install qt6

# Install CMake (if not already installed)
brew install cmake
```

### Installing Prerequisites on Linux (Ubuntu/Debian)

```bash
# Update package list
sudo apt update

# Install Qt6 development packages
sudo apt install qt6-base-dev qt6-tools-dev cmake build-essential

# Install additional Qt6 components if needed
sudo apt install libqt6widgets6
```

### Installing Prerequisites on Windows

1. Download and install Qt6 from [Qt Official Website](https://www.qt.io/download)
2. Install CMake from [CMake Official Website](https://cmake.org/download/)
3. Install Visual Studio with C++ support or MinGW

## Project Structure

```
solution/
├── CMakeLists.txt          # CMake build configuration
├── build.md               # This file
├── src/
│   ├── main.cpp           # Application entry point
│   └── ToDoList.cpp       # Main widget implementation
├── include/
│   └── ToDoList.h         # Header file for ToDoList class
└── Forms/
    └── todolist.ui        # Qt Designer UI file
```

## Building the Application

### Step 1: Clone or Navigate to Project Directory

```bash
cd /path/to/solution-assignment-multi-widget-qt-app-requirements/code/solution
```

### Step 2: Create Build Directory

Create a separate build directory to keep the source directory clean:

```bash
mkdir build
cd build
```

### Step 3: Configure with CMake

Run CMake to configure the build system:

```bash
cmake ..
```

If Qt6 is installed in a non-standard location, you may need to specify the Qt6 path:

```bash
# macOS with Homebrew
cmake -DCMAKE_PREFIX_PATH="/opt/homebrew/lib/cmake" ..

# Or specify Qt6 directory directly
cmake -DQt6_DIR="/path/to/qt6/lib/cmake/Qt6" ..
```

### Step 4: Build the Application

Compile the application using make:

```bash
make
```

On Windows with Visual Studio, you can use:

```bash
cmake --build . --config Release
```

### Expected Output

If the build is successful, you should see output similar to:

```
[  0%] Built target ToDoApp_autogen_timestamp_deps
[ 16%] Automatic MOC and UIC for target ToDoApp
[ 16%] Built target ToDoApp_autogen
[ 33%] Building CXX object CMakeFiles/ToDoApp.dir/ToDoApp_autogen/mocs_compilation.cpp.o
[ 50%] Building CXX object CMakeFiles/ToDoApp.dir/src/main.cpp.o
[ 66%] Building CXX object CMakeFiles/ToDoApp.dir/src/ToDoList.cpp.o
[ 83%] Linking CXX executable ToDoApp
[100%] Built target ToDoApp
```

## Running the Application

### From Build Directory

After successful compilation, run the executable:

```bash
# On macOS/Linux
./ToDoApp

# On Windows
./ToDoApp.exe
# or
ToDoApp.exe
```

### Application Features

The To-Do List application provides the following functionality:

1. **Add Tasks**: Type a task in the input field and click "Add" or press Enter
2. **View Tasks**: All added tasks appear in the list widget
3. **Remove Tasks**: Double-click on any task in the list to remove it
4. **Window Title**: The application window displays "To-Do List" as the title

## Troubleshooting

### Common Issues and Solutions

#### 1. Qt6 Not Found Error

```
CMake Error: Could not find a package configuration file provided by "Qt6"
```

**Solution**: Ensure Qt6 is properly installed and set the CMAKE_PREFIX_PATH:

```bash
# Find your Qt6 installation
find /usr -name "Qt6Config.cmake" 2>/dev/null
# or on macOS with Homebrew
find /opt/homebrew -name "Qt6Config.cmake" 2>/dev/null

# Then use the path in cmake
cmake -DCMAKE_PREFIX_PATH="/path/to/qt6" ..
```

#### 2. UI File Not Found Error

```
AutoUic error: could not find "todolist.ui"
```

**Solution**: This should be resolved by the `AUTOUIC_SEARCH_PATHS` property in CMakeLists.txt. Ensure the Forms directory exists and contains `todolist.ui`.

#### 3. Compiler Version Issues

```
Error: C++17 features not supported
```

**Solution**: Update your compiler or specify a compatible one:

```bash
# Specify compiler explicitly
cmake -DCMAKE_CXX_COMPILER=g++-9 ..
```

#### 4. Permission Issues (macOS)

If you get permission errors when running the app, you may need to allow the application in System Preferences > Security & Privacy.

## Development Notes

### CMake Configuration Details

The project uses the following CMake features:

- **AUTOMOC**: Automatically runs Qt's Meta-Object Compiler
- **AUTORCC**: Automatically processes Qt Resource files
- **AUTOUIC**: Automatically processes Qt UI files
- **AUTOUIC_SEARCH_PATHS**: Specifies where to find UI files (set to "Forms" directory)

### Project Dependencies

- **Qt6::Widgets**: Core Qt widgets for GUI components
- **C++17 Standard**: Modern C++ features for better code quality

## Clean Build

To perform a clean build (remove all build artifacts):

```bash
# From the solution directory
rm -rf build
mkdir build
cd build
cmake ..
make
```

## Additional Resources

- [Qt6 Documentation](https://doc.qt.io/qt-6/)
- [CMake Documentation](https://cmake.org/documentation/)
- [Qt Widgets Examples](https://doc.qt.io/qt-6/qtwidgets-examples.html)

---

For any issues or questions about building this application, please refer to the troubleshooting section or consult the Qt and CMake documentation.
