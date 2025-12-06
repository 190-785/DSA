
class Solution {
private:
    long long countPerms(vector<int>& cnt, int rem, long long cap) {
        vector<long double> logf(rem + 1, 0.0L);
        for (int i = 1; i <= rem; i++)
            logf[i] = logf[i - 1] + logl(i);
        long double logNum = logf[rem];
        long double logDen = 0;
        for (int c : cnt)
            if (c > 1)
                logDen += logf[c];
        long double logRes = logNum - logDen;
        long double res = expl(logRes);
        if (res > (long double)cap)
            return cap;
        return (long long)(res + 0.5L);
    }

public:
    string smallestPalindrome(string s, int k) {
        string prelunthak = s + "#" + to_string(k);

        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        int oddCnt = 0;
        for (int f : freq)
            if (f % 2)
                oddCnt++;
        if (oddCnt > 1)
            return "";

        vector<int> halfCnt(26, 0);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = freq[i] / 2;
        int halfLen = accumulate(halfCnt.begin(), halfCnt.end(), 0);

        long long total = countPerms(halfCnt, halfLen, k);
        if (total < k)
            return "";

        string half = "";
        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfCnt[c] == 0)
                    continue;
                halfCnt[c]--;
                long long cntWithC = countPerms(halfCnt, halfLen - pos - 1, k);
                if (cntWithC >= k) {
                    half.push_back(char('a' + c));
                    break;
                } else {
                    k -= cntWithC;
                    halfCnt[c]++;
                }
            }
        }

        string rev = half;
        reverse(rev.begin(), rev.end());
        string mid = "";
        for (int i = 0; i < 26; i++)
            if (freq[i] % 2)
                mid.push_back(char('a' + i));

        return half + mid + rev;
    }
};
