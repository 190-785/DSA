#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;    
// The solution class as provided in the problem description
class Solution {
public:
    /**
     * @brief Calculates the maximum number of alien ships that can be eliminated.
     * * @param dist A vector of integers representing the initial distances of the ships.
     * @param speed A vector of integers representing the speeds of the ships.
     * @return The maximum number of ships that can be destroyed.
     */
    int eliminateMaximum(vector<int>& dist, vector<int>& speed);
};

int Solution::eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    if (n == 0) {
        return 0;
    }

    // Step 1: Calculate the arrival time for each ship.
    // time = distance / speed. We use double for precision.
    vector<double> arrival_times;
    for (int i = 0; i < n; ++i) {
        arrival_times.push_back(static_cast<double>(dist[i]) / speed[i]);
    }

    // Step 2: Sort the arrival times in ascending order. This prioritizes the most immediate threats.
    sort(arrival_times.begin(), arrival_times.end());

    // Step 3: Iterate through time and see how many ships can be destroyed.
    int ships_destroyed = 0;
    int time_elapsed = 0; // Represents the time the cannon is ready to fire.

    for (int i = 0; i < n; ++i) {
        // The cannon is ready at 'time_elapsed'.
        // The current target ship (i-th in the sorted list) arrives at arrival_times[i].
        
        // If the ship arrives *after* the cannon is charged, we can destroy it.
        // If arrival_times[i] <= time_elapsed, the ship reaches Earth at or before we can fire.
        if (arrival_times[i] > time_elapsed) {
            // Success! Destroy the ship.
            ships_destroyed++;
            // The cannon takes one minute to charge for the next shot.
            time_elapsed++; 
        } else {
            // We lose. The ship arrived too soon. We can't destroy this or any subsequent ships.
            break;
        }
    }

    return ships_destroyed;
}

// Main function to demonstrate the solution with the examples from the problem.
int main() {
    Solution sol;

    // Example 1
    vector<int> dist1 = {1, 3, 4};
    vector<int> speed1 = {1, 1, 1};
    cout << "--- Example 1 ---" << endl;
    cout << "Input: dist = [1, 3, 4], speed = [1, 1, 1]" << endl;
    cout << "Output: " << sol.eliminateMaximum(dist1, speed1) << endl; // Expected: 3

    // Example 2
    vector<int> dist2 = {1, 1, 2, 3};
    vector<int> speed2 = {1, 1, 1, 1};
    cout << "\n--- Example 2 ---" << endl;
    cout << "Input: dist = [1, 1, 2, 3], speed = [1, 1, 1, 1]" << endl;
    cout << "Output: " << sol.eliminateMaximum(dist2, speed2) << endl; // Expected: 1

    // Example 3
    vector<int> dist3 = {3, 2, 4};
    vector<int> speed3 = {5, 3, 2};
    cout << "\n--- Example 3 ---" << endl;
    cout << "Input: dist = [3, 2, 4], speed = [5, 3, 2]" << endl;
    cout << "Output: " << sol.eliminateMaximum(dist3, speed3) << endl; // Expected: 1

    return 0;
}