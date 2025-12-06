class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *(max_element(weights.begin(), weights.end()));
        int end = accumulate(weights.begin(), weights.end(), 0);

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int Dsum = 0;
            int count = 1;
            for (int i = 0; i < weights.size(); i++) {
                if (Dsum + weights[i] > mid) {
                    count++;
                    Dsum = weights[i];
                } else {
                    Dsum += weights[i];
                }
                if (count > days) {
                    break;
                }
            }
            if (count > days) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};