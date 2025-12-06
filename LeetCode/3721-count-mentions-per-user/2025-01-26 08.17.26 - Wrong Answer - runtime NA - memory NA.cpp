#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> offlineHeap;

        for (const auto& event : events) {
            string eventType = event[0];
            int timestamp = stoi(event[1]);
            string data = event[2];
            while (!offlineHeap.empty() && offlineHeap.top().first <= timestamp) {
                int userId = offlineHeap.top().second;
                online[userId] = true;
                offlineHeap.pop(); 
            }

            if (eventType == "OFFLINE") {
                int userId = stoi(data);
                online[userId] = false;
                offlineHeap.push({timestamp + 60, userId}); 
            } 
            else if (eventType == "MESSAGE") {
                if (data == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } else if (data == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (online[i]) {
                            mentions[i]++;
                        }
                    }
                } else {
                    stringstream ss(data);
                    string token;
                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                            mentions[userId]++;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};
