class Solution {
public:
    int score(vector<string>& cards, char x) {
        unordered_map<string, int> freq;
        vector<string> containsX;
        for (const string& card : cards) {
            if (card[0] == x || card[1] == x) {
                containsX.push_back(card);
            }
        }
        for (const string& card : containsX) {
            freq[card]++;
        }
        int points = 0;
        for (const string& card : containsX) {
            if (freq[card] == 0)
                continue;
            for (char c = 'a'; c <= 'j'; c++) {
                for (int i = 0; i < 2; i++) {
                    if (card[i] == c)
                        continue;

                    string neighbor = card;
                    neighbor[i] = c;
                    if (neighbor == card || freq[neighbor] == 0)
                        continue;
                    freq[card]--;
                    freq[neighbor]--;
                    points++;
                    break;
                }
                if (freq[card] == 0)
                    break;
            }
        }
        return points;
    }
};