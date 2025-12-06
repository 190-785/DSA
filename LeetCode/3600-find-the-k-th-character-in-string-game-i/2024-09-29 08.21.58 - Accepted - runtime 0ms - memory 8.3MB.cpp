class Solution {
public:
    char kthCharacter(int k) {
        vector<char> string;
        string.push_back('a');
        while (string.size() < k) {
            int currentSize = string.size();
            for (int i = 0; i < currentSize; i++) {
                char temp = string[i];
                if (temp == 'z') {
                    string.push_back('a');
                } else {
                    string.push_back(temp + 1);
                }
                if (string.size() >= k) {
                    return string[k - 1];
                }
            }
        }
        return string[k - 1];
    }
};