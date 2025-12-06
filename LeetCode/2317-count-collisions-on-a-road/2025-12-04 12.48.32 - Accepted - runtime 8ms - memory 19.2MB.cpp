class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int noCollisionL = 0, noCollisionR = 0;
        int sCount = 0;
        for (int i = 0; i < n; i++) {
            if (directions[i] == 'L')
                noCollisionL++;
            else
                break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (directions[i] == 'R')
                noCollisionR++;
            else
                break;
        }
        for (int i = 0; i < n; i++)
            if (directions[i] == 'S')
                sCount++;
        return n - noCollisionL - noCollisionR - sCount;
    }
};