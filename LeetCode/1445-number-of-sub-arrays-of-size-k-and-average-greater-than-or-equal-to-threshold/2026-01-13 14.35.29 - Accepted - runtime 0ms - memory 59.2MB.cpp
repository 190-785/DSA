class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int n = arr.size();
        int currSum = 0;
        int i = 0, j = 0;
        int currLen = 0;
        while (i < n) {
            currSum += arr[i];
            currLen++;
            if (currLen == k && currSum/k >= threshold) {
                res++;
                currSum -= arr[j];
                j++;
                currLen--;
            }
            else if(currLen==k && currSum/k<threshold){
                currSum-=arr[j];
                j++;
                currLen--;
            }
            i++;
        }
        return res;
    }
};