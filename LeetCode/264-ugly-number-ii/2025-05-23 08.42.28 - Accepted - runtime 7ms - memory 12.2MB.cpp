class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> h(1, 1);
        int i = 0, j = 0, k = 0;

        for (int count = 1; count < n; count++) {
            int m = min({h[i] * 2, h[j] * 3, h[k] * 5});
            h.push_back(m);

            if (m == h[i] * 2)
                i++;
            if (m == h[j] * 3)
                j++;
            if (m == h[k] * 5)
                k++;
        }

        return h.back();
    }
};
