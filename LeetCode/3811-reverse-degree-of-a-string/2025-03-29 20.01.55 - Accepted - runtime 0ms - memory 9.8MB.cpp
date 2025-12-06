class Solution {
public:
    int reverseDegree(string s) {
        int reverseDegree = 0;
        for (int i = 0; i < s.length(); i++) {
            int rAlp = 'z' - s[i] + 1; 
            reverseDegree += rAlp * (i + 1); 
        }
        return reverseDegree;
    }
};
