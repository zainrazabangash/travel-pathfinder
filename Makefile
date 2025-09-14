# Makefile for Travel Pathfinder System
# Developer: Muhammad Zain Raza, BS AI, FAST NUCES Islamabad

# Compiler
CXX = g++

# Compile and build
all:
	g++ -o main Main.cpp ProjectMain.cpp

# Clean build files
clean:
	del *.o main.exe

# Run the program
run: all
	main.exe
