#ifndef HEADER_H
#define HEADER_H

// NODE CLASS

class node
{
    public:
        int cityNumber;
        node* next;
        node* arial;

        node(int);
        ~node(); // Destructor for proper memory cleanup
};


// GRAPH CLASS

class Graph
{
    private:
        int cities;
        node* head;
        node* tail;

    public:
        Graph();
        Graph(int);
        ~Graph(); // Destructor for proper memory cleanup
        int getHead();
        void addCity(int);
        void addAerial(int, int);
        void printGraph();
        void printAerial();
        void printPath(int[], int);
        void printDetailedPath(int[], int, int); // Enhanced path visualization
        void BFS(int);
        void runCode();
        void runCodeInteractive(); // Interactive version with menu
        void runCodeSimple(); // Simple version for project requirements
        void clearGraph(); // Helper method to clear the graph
        void showMenu(); // Interactive menu system
        void showStatistics(int aerialRoutes); // Performance statistics
        void calculateCost(int, bool); // Travel cost calculator
};

#endif