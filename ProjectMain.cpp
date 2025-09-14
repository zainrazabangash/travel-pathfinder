#include "Project.h"
#include <iostream>
#include <iomanip>
using namespace std;

// DEFINITION OF CLASS "node"

node ::node(int cityNumber)
{
    this->cityNumber = cityNumber;
    this->next = NULL;
    this->arial = NULL;
}

node ::~node()
{
    // Destructor - no dynamic memory to free in node itself
    // The Graph destructor will handle the linked list cleanup
}

// -------- DEFINITION ENDS HERE --------

// -----------------------------------------------

// DEFINITION OF CLASS "Graph"

Graph :: Graph()
{
    this->cities = 0;
    this->head = NULL;
    this->tail = NULL;
}

Graph :: Graph(int cities)
{
    this->cities = cities;
    this->head = NULL;
    this->tail = NULL;
}

Graph :: ~Graph()
{
    clearGraph();
}

void Graph :: clearGraph()
{
    node* current = head;
    while (current != NULL)
    {
        node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    cities = 0;
}

int Graph :: getHead()
{
    if (head == NULL)
    {
        return -1; // Return -1 if no head exists
    }
    return head->cityNumber;
}

void Graph :: addCity(int cityNumber)
{
    node *temp = new node(cityNumber);

    if (this->head == NULL)
    {
        this->head = temp;
        this->tail = temp;
        // cout << "1st added" << endl;
    }
    else
    {
        this->tail->next = temp;
        this->tail = temp;
        // cout << "added" << endl;
    }
}

void Graph :: addAerial(int source, int destination)
{
    // Validate input - cities should be between 1 and cities
    if (source < 1 || source > cities || destination < 1 || destination > cities)
    {
        cout << "Error: Invalid city number. City numbers must be between 1 and " << cities << endl;
        cout << "Enter the correct source of the aerial route: ";
        cin >> source;
        cout << "Enter the correct destination of the aerial route: ";
        cin >> destination;
        addAerial(source, destination);
        return;
    }

    // source: jis se arial route start ho rha hai
    // destination: jis pe arial route end ho rha hai

    node *temp = this->head;
    bool added = false;

    while (temp != NULL)
    {
        if (temp->cityNumber == source) // pehle source city ko find kr rhe hum
        {
            node *temp2 = this->head;
            while (temp2 != NULL)
            {
                if (temp2->cityNumber == destination) // phir destination city ko find kr rhe hum
                {
                    temp->arial = temp2; // agr mil jaye tou source city ke arial mai destination city ko add krdo
                    added = true;        // and flag ko true krdo
                    break;
                }
                temp2 = temp2->next;
            }
            break;
        }
        temp = temp->next;
    }

    try
    {
        if (!added) // agr source ya destination mai se koi bhe ya dono city graph mai nhi hai tou exception throw kro
        {
            throw "The source or destination city is not present in the graph";
        }
    }
    catch (const char *msg)
    {
        cerr << msg << endl;        // error show kro user ko

        // and phir user se source and destination city ko dubara input krwao
        int source, destination;

        cout << endl << "Enter the correct source of the aerial route: ";
        cin >> source;

        cout << "Enter the correct destination of the aerial route: ";
        cin >> destination;

        addAerial(source, destination);
    }
}

void Graph :: printGraph()
{
    node *temp = this->head;
    while (temp != NULL)
    {
        cout << temp->cityNumber << " -> ";
        temp = temp->next;
    }
}

void Graph :: printAerial()
{
    node *temp = this->head;
    while (temp != NULL)
    {
        // cout << temp->cityNumber << " -> ";
        // if (temp->arial != NULL)
        // {
        //     cout << temp->arial->cityNumber << endl;
        // }
        // else
        // {
        //     cout << "NULL" << endl;
        // }
        // temp = temp->next;

        if (temp->arial != NULL)
        {
            cout << temp->cityNumber << " -> " << temp->arial->cityNumber << endl;
        }
        temp = temp->next;
    }
}

void Graph :: printPath(int parent[], int currentCity)
{
    if (currentCity == -1)          // source city ka parent -1 rkha howa tou jab odhr ponch jaye tou return krdo
    {
        return;
    }

    printPath(parent, parent[currentCity]);              // moving back to the parent of the current city till we reach the source city
    cout << currentCity << " -> ";      
}

void Graph :: printDetailedPath(int parent[], int currentCity, int days)
{
    if (currentCity == -1)          // source city ka parent -1 rkha howa tou jab odhr ponch jaye tou return krdo
    {
        return;
    }

    printDetailedPath(parent, parent[currentCity], days);              // moving back to the parent of the current city till we reach the source city
    cout << currentCity << " -> ";      
}

void Graph :: BFS(int source)       // source is always 1 (first city)
{
    int visited[this->cities + 1] = {0};                        // visited check rkhne k liye (1-indexed)
    int distance[this->cities + 1] = {0};                       // distance of each city from source
    int parent[this->cities + 1] = {0};                         // parents of each city

    int daysCount = 0;                              // days counter to keep track of the number of days required to travel from city 1 to last city
    int citiesCount = 0;                            // cities counter to keep track of the number of cities travelled from city 1 to last city

    node *temp = this->head;

    visited[source] = 1;                        // source city visited hee hoge
    distance[source] = 0;                       // or source se source tk distance 0 hee hoge
    parent[source] = -1;                        // source k parent ko -1 rkha howa hai

    int queue[this->cities + 1];                    // queue to keep track of the cities jo visited hoye ve ho
    int front = 0;
    int rear = 0;

    queue[rear] = source;                       // starting from source
    rear++;

    while (front != rear)
    {
        int current = queue[front];                     // current city is the front of the queue.
        front++;                                        // current city store krne k baad front ko increment kr rhe taa k next city pe jaa sakay

        temp = this->head;

        while (temp != NULL)
        {
            if (temp->cityNumber == current)            // current city find kr rha and then ospe baqi operations perform kr rha
            {
                if (temp->arial != NULL)                // agr current city se flight hai tou phir ismai ayega
                {
                    if (visited[temp->arial->cityNumber] == 0)              // if the destination city of the arial route is not visited
                    {
                        visited[temp->arial->cityNumber] = 1;
                        distance[temp->arial->cityNumber] = distance[temp->cityNumber] + 1;
                        parent[temp->arial->cityNumber] = temp->cityNumber;
                        queue[rear] = temp->arial->cityNumber;
                        rear++;

                        /* agr current city kee next city visited nae hai tou osko queue mai add krdo or oska jo distance hoga wo current city se 1 ziada hoga
                           or osko visited check krlo and oske parent ko current city bna do or rear ko increment krdo taa k next city bhi queue mai add hojaye   
                        */

                        daysCount++;                                        // arial route se jayeinge tou aik din lagega

                        if (temp->arial->cityNumber == cities)          // if last city, tou loop break krdo
                        {
                            break;
                        }
                    }

                    else                // if the destination city of the arial route is visited tou phir oska distance compare kr rhe pechle saved distance se
                    {
                        if (distance[temp->arial->cityNumber] > distance[temp->cityNumber] + 1)
                        {
                            distance[temp->arial->cityNumber] = distance[temp->cityNumber] + 1;
                            parent[temp->arial->cityNumber] = temp->cityNumber;
                            queue[rear] = temp->arial->cityNumber;
                            rear++;

                            daysCount++;
                            citiesCount = 0;

                            if (temp->arial->cityNumber == cities)
                            {
                                break;
                            }
                        }
                    }
                }

                // else       // agr current city se aerial route nae hai tou phir
                // {
                if (temp->next != NULL)                                         // last city agr nae aye
                {
                    if (visited[temp->next->cityNumber] == 0)                   // next city agr visited nae hai
                    {
                        visited[temp->next->cityNumber] = 1;
                        distance[temp->next->cityNumber] = distance[temp->cityNumber] + 1;
                        parent[temp->next->cityNumber] = temp->cityNumber;
                        queue[rear] = temp->next->cityNumber;
                        rear++;
                    }

                    else                               // if the next city of the current city is visited
                    {
                        if (distance[temp->next->cityNumber] > distance[temp->cityNumber] + 1)
                        {
                            distance[temp->next->cityNumber] = distance[temp->cityNumber] + 1;
                            parent[temp->next->cityNumber] = temp->cityNumber;
                            queue[rear] = temp->next->cityNumber;
                            rear++;
                        }
                    }

                    citiesCount++;

                    if (citiesCount == 6)
                    {
                        daysCount++;                        // 6 cities visit krne k liye 1 din lagega
                    }
                }
                // }
            }
            temp = temp->next;
        }
    }

    // printing the shortest path from city 1 to last city

    int current = cities;               // current city ko last city k equal krdo

    cout << endl << endl << "The shortest path from city 1 to last city is: " << endl;

    this->printPath(parent, current);
    cout << "end of journey, yayy!!" << endl;

    cout << endl << "The minimum number of days required to travel from city 1 to last city is: " << daysCount << endl;
}

void Graph :: runCode()
{
    int testCases;
    cout << endl << "Enter the number of test cases: ";
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        cout << endl << "---- Test case " << i + 1 << " ----" << endl;

        int cities;

        cout << endl << "Enter the number of cities: ";
        cin >> cities;

        this->cities = cities;

        for (int j = 1; j <= cities; j++)
        {
            // cout << "City " << j << " added to the graph" << endl;
            this->addCity(j);
        }

        // cout << endl << "The head of the graph is: " << g.getHead() << endl;

        // cout << endl << "The graph is: " << endl;
        // g.printGraph();

        int aerialRoutes;

        cout << endl << "Enter the number of aerial routes: ";
        cin >> aerialRoutes;

        for (int j = 0; j < aerialRoutes; j++)
        {
            int source, destination;

            cout << endl << "Enter the source of the aerial route: ";
            cin >> source;

            cout << "Enter the destination of the aerial route: ";
            cin >> destination;

            this->addAerial(source, destination);

        }

        // Interactive menu for this test case
        int choice;
        bool usedAerial = false;
        int days = 0;
        
        do {
            this->showMenu();
            cin >> choice;
            
            switch(choice) {
                case 1:
                    cout << "\nFinding shortest path..." << endl;
                    this->BFS(1);
                    break;
                case 2:
                    cout << "\nAerial routes in the network:" << endl;
                    this->printAerial();
                    break;
                case 3:
                    cout << "\nRoad connections in the network:" << endl;
                    this->printGraph();
                    break;
                case 4:
                    cout << "\nCalculating travel cost..." << endl;
                    // Simple cost calculation - you can enhance this
                    this->calculateCost(3, true); // Example: 3 days, used aerial
                    break;
                case 5:
                    this->showStatistics(aerialRoutes);
                    break;
                case 6:
                    cout << "\nExiting test case " << (i + 1) << "..." << endl;
                    break;
                default:
                    cout << "\nInvalid choice! Please enter 1-6." << endl;
            }
        } while(choice != 6);

        this->clearGraph(); // Properly clear the graph for next test case

        cout << endl << "---- End of test case " << i + 1 << " ----" << endl;

    }
}

void Graph :: runCodeSimple()
{
    int testCases;
    cout << endl << "Enter the number of test cases: ";
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        cout << endl << "---- Test case " << i + 1 << " ----" << endl;

        int cities;
        cout << endl << "Enter the number of cities: ";
        cin >> cities;

        this->cities = cities;

        for (int j = 1; j <= cities; j++)
        {
            this->addCity(j);
        }

        int aerialRoutes;
        cout << endl << "Enter the number of aerial routes: ";
        cin >> aerialRoutes;

        for (int j = 0; j < aerialRoutes; j++)
        {
            int source, destination;
            cout << endl << "Enter the source of the aerial route: ";
            cin >> source;
            cout << "Enter the destination of the aerial route: ";
            cin >> destination;
            this->addAerial(source, destination);
        }
        
        this->BFS(1);
        this->clearGraph();
        cout << endl << "---- End of test case " << i + 1 << " ----" << endl;
    }
}

void Graph :: runCodeInteractive()
{
    cout << "\n" << string(60, '=') << endl;
    cout << "    WELCOME TO ADVANCED TRAVEL PLANNER SYSTEM" << endl;
    cout << string(60, '=') << endl;
    cout << "This system helps you find the shortest path between cities" << endl;
    cout << "with both road and aerial route options!" << endl;
    cout << string(60, '=') << endl;
    
    runCode(); // Use the interactive version
}

// ===== BONUS FEATURES =====

void Graph :: showMenu()
{
    cout << "\n" << string(50, '=') << endl;
    cout << "           TRAVEL PLANNER MENU" << endl;
    cout << string(50, '=') << endl;
    cout << "1. Find shortest path (City 1 to last city)" << endl;
    cout << "2. Show all aerial routes" << endl;
    cout << "3. Show road connections only" << endl;
    cout << "4. Calculate travel cost" << endl;
    cout << "5. Show network statistics" << endl;
    cout << "6. Exit" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice (1-6): ";
}

void Graph :: showStatistics(int aerialRoutes)
{
    cout << "\n" << string(50, '=') << endl;
    cout << "        TRAVEL NETWORK STATISTICS" << endl;
    cout << string(50, '=') << endl;
    cout << "Total cities in network: " << cities << endl;
    cout << "Aerial routes available: " << aerialRoutes << endl;
    cout << "Road connectivity: " << (cities - 1) << " sequential connections" << endl;
    cout << "Aerial coverage: " << fixed << setprecision(1) << (aerialRoutes * 100.0 / cities) << "% of cities have aerial routes" << endl;
    cout << string(50, '=') << endl;
}

void Graph :: calculateCost(int days, bool usedAerial)
{
    int roadCost = days * 1500;  // asssume kro Rs 1500 per day for road travel
    int aerialCost = usedAerial ? 6000 : 0;  // Rs 6000 for aerial route
    int totalCost = roadCost + aerialCost;
    
    cout << endl << string(50, '=') << endl;
    cout << "        TRAVEL COST CALCULATION" << endl;
    cout << string(50, '=') << endl;
    cout << "Days of travel: " << days << endl;
    cout << "Road travel cost: Rs " << roadCost << " (Rs 1500/day)" << endl;
    if (usedAerial)
    {
        cout << "Aerial route cost: Rs 6000 (one-time)" << endl;
    }
    else
    {
        cout << "Aerial route cost: Rs 0 (not used)" << endl;
    }
    cout << string(30, '-') << endl;
    cout << "TOTAL ESTIMATED COST: Rs " << totalCost << endl;
    cout << string(50, '=') << endl;
}

// -------- DEFINITION ENDS HERE --------