class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majEl[2][2] = {{0, 0}, {0, 0}};
        for (int num : nums) {
            if (majEl[0][0] == num) {
                majEl[0][1]++;
            } else if (majEl[1][0] == num) {
                majEl[1][1]++;
            } else if (majEl[0][1] == 0) {
                majEl[0][0] = num;
                majEl[0][1] = 1;
            } else if (majEl[1][1] == 0) {
                majEl[1][0] = num;
                majEl[1][1] = 1;
            } else {
                majEl[0][1]--;
                majEl[1][1]--;
            }
        }

        // Verify the candidates
        vector<int> result;
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == majEl[0][0]) count1++;
            else if (num == majEl[1][0]) count2++;
        }

        if (count1 > nums.size() / 3) result.push_back(majEl[0][0]);
        if (count2 > nums.size() / 3) result.push_back(majEl[1][0]);

        return result;
    }
};
