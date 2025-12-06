class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        long long end;
        end = *max_element(piles.begin(), piles.end());
        while (start <= end) {
            long long sum = 0;
            int mid = start + (end - start) / 2;
            for (int i = 0; i < piles.size(); i++) {
                sum += (piles[i] + mid - 1) / mid;
                if (sum > h) {
                    break;
                }
            }
            if (sum > h) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};