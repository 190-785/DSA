class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k > n) return 0;
        
        int count = 0;
        int alternatingCount = 0;

        for (int i = 0; i < k - 1; ++i) {
            if (colors[i] != colors[i + 1]) {
                alternatingCount++;
            }
        }

        for (int i = 0; i < n; ++i) {
            int start = i;
            int end = (i + k - 1) % n;
            
            if (alternatingCount == k - 1) {
                count++;
            }

            int out = colors[start];
            int in = colors[(start + k) % n];
            
            if (k > 1) {
                if (colors[start] != colors[(start + 1) % n]) {
                    alternatingCount--;
                }
                if (colors[end] != in) {
                    alternatingCount++;
                }
            }
        }
        
        return count;
    }
};
