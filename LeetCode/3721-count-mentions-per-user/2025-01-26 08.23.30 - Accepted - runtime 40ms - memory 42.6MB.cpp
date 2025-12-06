class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0); 
        vector<bool> online(numberOfUsers, true); 
        map<int, int> offlineUntil; 
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA == timeB) {
                return a[0] == "OFFLINE" && b[0] == "MESSAGE";
            }
            return timeA < timeB;
        });

        for (const auto& event : events) {
            string eventType = event[0];
            int timestamp = stoi(event[1]);
            string data = event[2];

            for (auto& [userId, time] : offlineUntil) {
                if (timestamp >= time) {
                    online[userId] = true;
                }
            }
            if (eventType == "OFFLINE") {
                int userId = stoi(data);
                online[userId] = false;
                offlineUntil[userId] = timestamp + 60; 
            } 
            else if (eventType == "MESSAGE") {
                if (data == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        mentions[i]++;
                    }
                }
                else if (data == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (online[i]) {
                            mentions[i]++;
                        }
                    }
                }
                else {
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
