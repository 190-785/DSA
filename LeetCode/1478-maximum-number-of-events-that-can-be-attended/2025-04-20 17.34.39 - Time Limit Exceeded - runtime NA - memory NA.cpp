class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int maxDay = 0;
        for (const auto& event : events) {
            maxDay = max(maxDay, event[1]);
        }

        vector<int> slot(maxDay + 1, 0);
        int attended = 0;

        for (const auto& event : events) {
            for (int day = event[0]; day <= event[1]; day++) {
                if (slot[day] == 0) {
                    slot[day] = 1;
                    attended++;
                    break;
                }
            }
        }

        return attended;
    }
};
