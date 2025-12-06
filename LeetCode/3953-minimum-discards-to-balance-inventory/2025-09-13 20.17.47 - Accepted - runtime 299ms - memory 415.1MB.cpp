class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, queue<int>> kept;
        int disc = 0;
        int n = arrivals.size();
        for (int i = 0; i < n; i++) {
            int curr = i;
            int type = arrivals[i];
            queue<int>& item = kept[type];
            int windowStart = curr - w + 1;
            while (!item.empty() && item.front() < windowStart)
                item.pop();
            if (item.size() < m)
                item.push(curr);
            else
                disc++;
        }
        return disc;
    }
};