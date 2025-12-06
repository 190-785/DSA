class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> replace;
        for (int num : nums) {
            while (!replace.empty() && gcd(replace.back(), num) > 1) {
                num = lcm(replace.back(), num);
                replace.pop_back();
            }
            replace.push_back(num);
        }
        return replace;
    }
};
