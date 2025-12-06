class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<bool> busy(days + 1, false);
        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            for (int i = start; i <= end; ++i) {
                busy[i] = true;
            }
        }

        int freeDays = 0;
        for (int i = 1; i <= days; ++i) {
            if (!busy[i]) {
                ++freeDays;
            }
        }

        return freeDays;
    }
};
