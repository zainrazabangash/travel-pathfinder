# Travel Pathfinder System

A Data Structures project implementing a graph-based pathfinding algorithm to find the shortest travel route between cities with both road and aerial connections.

## Developer

**Muhammad Zain Raza**  
Student of BS AI at FAST NUCES Islamabad

## Project Description

This project solves the problem of finding the minimum number of days required to travel from the first city to the last city, considering:

- **Road Travel**: Maximum 6 cities per day
- **Aerial Travel**: Instant travel (1 day) between connected cities
- **Constraint**: Cannot stop in cities that have aerial routes back to previously visited cities

The system uses a graph data structure with linked lists to represent cities and their connections, implementing Breadth-First Search (BFS) algorithm for optimal pathfinding.

## Features

### Core Functionality
- Graph representation of cities and connections
- BFS algorithm for shortest path calculation
- Support for both road and aerial routes
- Input validation for city numbers
- Memory management with proper destructors

### Interactive Mode (Bonus Features)
- User-friendly menu system
- Detailed path visualization
- Network statistics and analysis
- Travel cost calculation (in Pakistani Rupees)
- Road and aerial route display options

## File Structure

```
├── Main.cpp              # Main entry point with mode selection
├── Project.h             # Header file with class definitions
├── ProjectMain.cpp       # Implementation of all methods
├── README.md            # Project documentation
├── .gitignore           # Git ignore file
└── main.exe             # Compiled executable (generated)
```

## Classes

### Node Class
- Represents a city in the graph
- Contains city number, next pointer (road connection), and aerial pointer
- Includes destructor for memory cleanup

### Graph Class
- Manages the collection of cities
- Implements BFS algorithm
- Handles input/output operations
- Provides interactive menu system

## How to Use

### Method 1: Using Makefile (Recommended)
```bash
make all
make run
```

### Method 2: Direct Compilation
```bash
g++ -o main Main.cpp ProjectMain.cpp
main.exe
```

### Method 3: Using Make Commands
- `make` or `make all` - Compile the project
- `make run` - Compile and run the program
- `make clean` - Remove compiled files

### Input Format
1. Number of test cases
2. For each test case:
   - Number of cities
   - Number of aerial routes
   - Source and destination for each aerial route

### Sample Input
```
Number of test cases: 2

--- Test case 1 ---
Number of cities: 30
Number of aerial routes: 5

Aerial routes:
Source: 2 
Destination: 21
Source: 4 
Destination: 7
Source: 10 
Destination: 25
Source: 19 
Destination: 28
Source: 26 
Destination: 1


--- Test case 2 ---
Number of cities: 98
Number of aerial routes: 3

Aerial routes:
Source: 5 
Destination: 29
Source: 35 
Destination: 23
Source: 24 
Destination: 95
```

### Expected Output
```
Test case 1: 3 days
Test case 2: 4 days
```

## Algorithm Details

The BFS algorithm works as follows:

1. **Initialization**: Start from city 1 with distance 0
2. **Queue Processing**: Process cities level by level
3. **Road Travel**: Move to next city (up to 6 cities per day)
4. **Aerial Travel**: Check for aerial routes and jump to destination
5. **Constraint Handling**: Avoid cities with return aerial routes
6. **Path Tracking**: Maintain parent array for path reconstruction

## Technical Implementation

- **Data Structure**: Linked list of nodes representing cities
- **Time Complexity**: O(V + E) where V is cities and E is connections
- **Space Complexity**: O(V) for visited array and queue
- **Memory Management**: Proper destructors and cleanup methods

## Bonus Features Implemented

1. **Interactive Menu System**: User-friendly interface with multiple options
2. **Enhanced Path Visualization**: Detailed travel plan display
3. **Network Statistics**: Comprehensive analysis of the travel network
4. **Cost Calculation**: Travel cost estimation in Pakistani Rupees
5. **Dual Mode Operation**: Simple mode for basic requirements, Interactive mode for enhanced features

## Error Handling

- Input validation for city numbers (1 to N)
- Memory leak prevention with proper destructors
- Graceful handling of invalid aerial route inputs
- User-friendly error messages

## Future Enhancements

- GUI implementation
- Real-time path visualization
- Database integration for city data
- Multi-threading for large networks
- Export functionality for travel plans

## License

This project is created for educational purposes as part of the Data Structures course at FAST NUCES Islamabad.

## Contributing

If you want to contribute to this project, feel free to fork the repository and create a pull request.   

## Issues

If you find any issues or have any suggestions, feel free to create an issue.

## Contact

For questions or suggestions, please contact me on my email: muhzainraza@gmail.com.