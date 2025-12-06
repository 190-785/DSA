class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int day = 0, attended = 0, i = 0, n = events.size();

        while (!minHeap.empty() || i < n) {
            if (minHeap.empty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]); 
                i++;
            }
            if (!minHeap.empty()) {
                minHeap.pop();
                attended++;
                day++;
            }
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }

        return attended;
    }
};
