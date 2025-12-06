class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = apples.size();
        int res = 0, day = 0;

        while (day < n || !pq.empty()) {
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }

            while (!pq.empty() &&
                   (pq.top().first <= day || pq.top().second == 0)) {
                pq.pop();
            }

            if (!pq.empty()) {
                auto [exp, cnt] = pq.top();
                pq.pop();
                res++;
                if (cnt > 1)
                    pq.push({exp, cnt - 1});
            }

            day++;
        }

        return res;
    }
};
