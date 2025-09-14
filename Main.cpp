#include "Project.h"
#include <iostream>
using namespace std;

int main()
{
    Graph g;
    
    cout << "\n" << string(60, '=') << endl;
    cout << "        DATA STRUCTURES FINAL PROJECT" << endl;
    cout << "         TRAVEL PATHFINDER SYSTEM" << endl;
    cout << string(60, '=') << endl;
    cout << "Choose your mode:" << endl;
    cout << "1. Simple Mode (Original Project Requirements)" << endl;
    cout << "2. Interactive Mode (With Bonus Features)" << endl;
    cout << string(60, '=') << endl;
    cout << "Enter your choice (1 or 2): ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "\nRunning in Simple Mode..." << endl;
        g.runCodeSimple();
    } else if (choice == 2) {
        cout << "\nRunning in Interactive Mode..." << endl;
        g.runCodeInteractive();
    } else {
        cout << "\nInvalid choice! Running in Simple Mode by default..." << endl;
        g.runCodeSimple();
    }
    
    cout << "\n" << string(60, '=') << endl;
    cout << "Thank you for using the Travel Pathfinder System!" << endl;
    cout << string(60, '=') << endl;
    
    return 0;
}