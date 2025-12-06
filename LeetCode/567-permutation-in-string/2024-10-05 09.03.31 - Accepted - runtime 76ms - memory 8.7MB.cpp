class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
            return false;

        int size = s1.size();
        int arr[26] = {0};

        for (int i = 0; i < size; i++) {
            arr[s1[i] - 'a']++;
        }

        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            int arr2[26] = {0};
            memcpy(arr2, arr, 26 * sizeof(int));

            for (int j = i; j < i + size; j++) {
                arr2[s2[j] - 'a']--;
            }

            bool isPermutation = true;
            for (int k = 0; k < 26; k++) {
                if (arr2[k] != 0) {
                    isPermutation = false;
                    break;
                }
            }

            if (isPermutation)
                return true;
        }

        return false;
    }
};
