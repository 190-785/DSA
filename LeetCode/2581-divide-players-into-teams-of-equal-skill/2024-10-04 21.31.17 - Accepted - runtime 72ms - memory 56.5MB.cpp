class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int temp = skill[0] + skill[n - 1];
        long long chem = 0;
        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n - i - 1] == temp) {
                chem += (skill[i] * skill[n - i - 1]);
                sum += (skill[i] + skill[n - i - 1]);
            } else {
                return -1;
            }
        }
        return chem;
    }
};