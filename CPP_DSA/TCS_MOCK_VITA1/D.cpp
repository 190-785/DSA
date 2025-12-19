/*BusCount
Problem Description
As the Transportation In-Charge of a reputed company, your responsibility is to ensure that buses are available for every employee and that they arrive on time.

Since pandemic restrictions have been lifted, but not completely, the number of people allowed on buses is still limited. Employees have started visiting the office regularly. You are given an M*M matrix, which represents the distance between each location. The value in the ith row and jth column represents the distance between the ith place and the jth place. Assume that all locations are connected by roads and that the first location is the office. The distance between the ith place and the jth place is the same as the distance between the jth place and the ith place. The top left element of this matrix is (0, 0) and is the Office location.

The number of people boarding the bus at each location is known a priori and is a part of the input.

Given the number of people that a bus can accommodate at one time, post restrictions, determine the number of buses required to pick up all employees. A bus can start from any location but must take only the shortest path from that location to the office. The bus can pick up employees at locations along its route. Assume that there is only one shortest route between the office and each remaining location.

Constraints
1 < M < 12

0 < 300 < Distance between locations

0 < 500 < Total number of employees

Input
First line consists of a single integer M, representing the number of locations including office.

Next M lines consist of M integers separated by space representing the distance matrix.

Next line consists of M-1 space separated integers representing the employees boarding at each corresponding location.

Last line consists of an integer representing the number of people that can travel in the bus at one time.

Output
Print a single integer representing the minimum number of buses required to pick up all employees.

Time Limit (secs)
1

Examples
Example 1

Input

4

0 10 10 30

10 0 30 20

10 30 0 10

30 20 10 0

23 52 11

25

Output

4

Explanation

The below diagram represents the above input.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@2f94c4db:image1.png

Based on the input, there are four locations, which we can be denoted as 0, 1, 2, and 3. The first location is the office, represented as 0 (visualized as "Off").

The shortest paths between individual location and office are,

Location 1-> office

Location 2-> office

Location 3-> Location 2-> office

The number of buses required will be 4: one bus from location 1, two buses from location 2, and one bus from location 3. The two buses starting at location 2 will pick up 50 people from there, and the remaining 2 people will board the bus coming from location 3.

Example 2

Input

5

0 10 10 60 60

10 0 30 10 10

10 30 0 30 30

60 10 30 0 30

60 10 30 30 0

15 15 15 15

25

Output

3

Explanation

For the given input the visualization of complete paths looks dense. Hence below image depicts only the shortest path from each location to office.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@2f94c4db:image2.png

Three buses will originate from locations 2, 3, and 4 respectively. The buses starting from locations 3 and 4 will need to travel through location 1. Since they have enough seats to pick up the employees from location 1, three buses are sufficient. Therefore, the output 3.*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int M;
    cin >> M;

    vector<vector<int>> distMatrix(M, vector<int>(M));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> distMatrix[i][j];
        }
    }

    vector<long long> employees(M, 0);
    for (int i = 1; i < M; i++)
    {
        cin >> employees[i];
    }

    int busCapacity;
    cin >> busCapacity;

    vector<int> distToOffice(M, 1e9);
    vector<int> parent(M, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distToOffice[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distToOffice[u])
        {
            continue;
        }

        for (int v = 0; v < M; v++)
        {
            if (distMatrix[u][v] != 0 && distToOffice[u] + distMatrix[u][v] < distToOffice[v])
            {
                distToOffice[v] = distToOffice[u] + distMatrix[u][v];
                parent[v] = u;
                pq.push({distToOffice[v], v});
            }
        }
    }

    vector<pair<int, int>> sortedLocations;
    for (int i = 1; i < M; i++)
    {
        sortedLocations.push_back({distToOffice[i], i});
    }
    sort(sortedLocations.rbegin(), sortedLocations.rend());

    long long totalBuses = 0;

    for (const auto &locPair : sortedLocations)
    {
        int currentLocation = locPair.second;
        long long peopleWaiting = employees[currentLocation];

        if (peopleWaiting <= 0)
        {
            continue;
        }

        long long busesNeeded = (peopleWaiting + busCapacity - 1) / busCapacity;
        totalBuses += busesNeeded;

        long long leftoverSeats = (busesNeeded * busCapacity) - peopleWaiting;

        int pathTracer = currentLocation;
        while (leftoverSeats > 0 && parent[pathTracer] != -1 && parent[pathTracer] != 0)
        {
            int nextStop = parent[pathTracer];
            long long peopleAtNextStop = employees[nextStop];

            if (peopleAtNextStop > 0)
            {
                long long canPickUp = min(peopleAtNextStop, leftoverSeats);
                employees[nextStop] -= canPickUp;
                leftoverSeats -= canPickUp;
            }
            pathTracer = nextStop;
        }
    }

    cout << totalBuses;

    return 0;
}