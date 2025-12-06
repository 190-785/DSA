class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            bool isAlternating = true;

            for (int j = 0; j < k - 1; ++j) {
                int current = colors[(i + j) % n];
                int next = colors[(i + j + 1) % n];
                
                if (current == next) {
                    isAlternating = false;
                    break;
                }
            }
            
            if (isAlternating) {
                count++;
            }
        }
        
        return count;
    }
};
