class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        /* ans=arr[high]+more
        more=k-missing
        ans=arr[high]+k-missing
        missing=arr[high]-high+1
        hence, ans=k+high+1
        //start=end+1 in
        */
        return start + k;
    }
};