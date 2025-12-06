class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        int power = 0;
        while (n) {
            int mod = n % 10;
            if (mod != 0) {
                res.push_back(mod * pow(10, power));
            }
            power++;
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};