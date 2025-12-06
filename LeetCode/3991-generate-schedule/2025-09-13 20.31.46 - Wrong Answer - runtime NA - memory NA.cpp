class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if (n % 2 == 0 || n < 5)
            return {};
        int m = n * (n - 1);
        vector<vector<int>> schedule;
        for (int s = 1; s <= (n - 1) / 2; s++) {
            for (int i = 0; i < n; i++) {
                int home = (2 * i * s) % n;
                int away = (2 * i * s + s) % n;
                schedule.push_back({home, away});
            }
        }
        for (int s = 1; s <= (n - 1) / 2; s++) {
            for (int i = 0; i < n; i++) {
                int away = (2 * i * s) % n;
                int home = (2 * i * s + s) % n;
                schedule.push_back({home, away});
            }
        }
        return schedule;
    }
};