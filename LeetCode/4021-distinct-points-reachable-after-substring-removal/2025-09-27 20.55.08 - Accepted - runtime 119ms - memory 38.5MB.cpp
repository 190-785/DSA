class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        // I really shouldn't be sitting like this while giving the contest
        // Really doesn't help with the typing accuracy
        set<pair<long long, long long>> dist;
        long long totalX = 0, totalY = 0, windowX = 0, windowY = 0;
        for (char move : s) {
            if (move == 'U')
                totalY--;
            else if (move == 'D')
                totalY++;
            else if (move == 'L')
                totalX--;
            else
                totalX++;
        }
        for (int i = 0; i < k; i++) {
            char move = s[i];
            if (move == 'U')
                windowY--;
            else if (move == 'D')
                windowY++;
            else if (move == 'L')
                windowX--;
            else
                windowX++;
        }
        dist.insert({totalX - windowX, totalY - windowY});
        for (int i = k; i < n; i++) {
            char newMove = s[i];
            if (newMove == 'U')
                windowY--;
            else if (newMove == 'D')
                windowY++;
            else if (newMove == 'L')
                windowX--;
            else
                windowX++;
            char oldMove = s[i - k];
            if (oldMove == 'U')
                windowY++;
            else if (oldMove == 'D')
                windowY--;
            else if (oldMove == 'L')
                windowX++;
            else
                windowX--;
            dist.insert({totalX - windowX, totalY - windowY});
        }
        // God I'm getting lazy
        return dist.size();
    }
};