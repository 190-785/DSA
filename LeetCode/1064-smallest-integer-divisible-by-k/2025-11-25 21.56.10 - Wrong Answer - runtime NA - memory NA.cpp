class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        __uint128_t n = 1;
        vector<int> rems;
        int sizeN = 1;
        while (true) {
            __uint128_t rem = n % k;
            if (rem == 0) {
                return sizeN;
            }
            if (find(rems.begin(), rems.end(), rem) != rems.end())
                return -1;
            rems.push_back(rem);
            n = (n * 10) + 1;
            sizeN++;
        }
        return -1;
    }
};