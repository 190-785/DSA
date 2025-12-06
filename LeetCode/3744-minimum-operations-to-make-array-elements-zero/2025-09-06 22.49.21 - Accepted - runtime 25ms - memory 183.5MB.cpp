class Solution {
public:
    vector<long long> buildPow4() {
        vector<long long> pow4;
        pow4.push_back(1);
        while (pow4.back() <= 1e9) {
            pow4.push_back(pow4.back() * 4);
        }
        return pow4;
    }

    long long sumOpsRange(long long l, long long r,
                          const vector<long long>& pow4) {
        long long total = 0;
        for (int k = 0; k < (int)pow4.size(); k++) {
            long long start = pow4[k];
            long long end =
                (k + 1 < (int)pow4.size() ? pow4[k + 1] - 1 : (long long)1e9);

            if (r < start)
                break;
            if (l > end)
                continue;

            long long lo = max(l, start);
            long long hi = min(r, end);
            if (lo <= hi) {
                total += (hi - lo + 1) * (k + 1);
            }
        }
        return total;
    }

    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> pow4 = buildPow4();
        long long ans = 0;

        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long total = sumOpsRange(l, r, pow4);
            ans += (total + 1) / 2;
        }

        return ans;
    }
};