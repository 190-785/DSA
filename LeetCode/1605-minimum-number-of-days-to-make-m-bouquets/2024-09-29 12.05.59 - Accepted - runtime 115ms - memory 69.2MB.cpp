class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *(min_element(bloomDay.begin(), bloomDay.end()));
        int end = *(max_element(bloomDay.begin(), bloomDay.end()));
        if(bloomDay.size()<m || bloomDay.size()<k){
            return -1;
        }
        if (bloomDay.size() < m*k)
            return -1;
        int mid = start + (end - start) / 2;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int sum = 0;
            int count = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    count++;
                    if (count == k) {
                        sum++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }
            if (sum < m) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};