class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0;
        int n = citations.size();
        int high = n - 1;
        int res = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] >= n - mid) {
                res = n - mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};