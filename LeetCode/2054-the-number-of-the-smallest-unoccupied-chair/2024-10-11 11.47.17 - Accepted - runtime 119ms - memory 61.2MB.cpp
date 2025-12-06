class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> arrival;
        for (int i = 0; i < n; i++) {
            arrival.push_back({times[i][0], i});
        }
        sort(arrival.begin(), arrival.end());
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; i++) {
            availableChairs.push(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            occupiedChairs;

        for (auto& [arrive, friendIndex] : arrival) {

            while (!occupiedChairs.empty() &&
                   occupiedChairs.top().first <= arrive) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            int chair = availableChairs.top();
            availableChairs.pop();

            if (friendIndex == targetFriend) {
                return chair;
            }

            occupiedChairs.push({times[friendIndex][1], chair});
        }

        return -1;
    }
};