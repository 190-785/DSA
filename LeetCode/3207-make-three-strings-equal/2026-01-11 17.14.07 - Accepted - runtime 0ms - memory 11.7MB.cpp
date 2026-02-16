class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int i = 0;
        while (i < n1 && i < n2 && i < n3) {
            if (s1[i] == s2[i] && s2[i] == s3[i])
                i++;
            else
                break;
        }
        return i == 0 ? -1 : (n1 + n2 + n3) - i * 3;
    }
};