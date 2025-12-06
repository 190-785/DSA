class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> index;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        unordered_map<int, int> longest;
        int maxLength = 0;
        
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < k; j++) {
                int i = index.find(arr[k] - arr[j]) != index.end() && index[arr[k] - arr[j]] < j ? index[arr[k] - arr[j]] : -1;
                if (i != -1) {
                    int length = longest[j * n + k] = longest[i * n + j] + 1;
                    maxLength = max(maxLength, length + 2);
                }
            }
        }
        
        return maxLength >= 3 ? maxLength : 0;
    }
};
