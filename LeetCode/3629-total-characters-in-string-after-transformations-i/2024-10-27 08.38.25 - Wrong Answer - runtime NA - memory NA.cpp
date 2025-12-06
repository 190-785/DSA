class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        long long length = s.size();
        long long arr[26] = {0};

        for (char c : s) {
            arr[c - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            long long new_arr[26] = {0};
            long long zz = 0;

            for (int j = 0; j < 26; j++) {
                if (arr[j] > 0) {
                    if (j == 25) {
                        zz += arr[j];
                    } else if (j == 24) {
                        new_arr[25] += arr[j];
                    } else {
                        new_arr[j + 1] += arr[j];
                    }
                }
            }

            length = (length + zz) % MOD;

            for (int j = 0; j < 26; j++) {
                arr[j] = new_arr[j];
            }
        }

        return (int)length;
    }
};