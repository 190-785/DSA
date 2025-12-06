class Solution {
public:
    string decimalToBin(int n) {
        return bitset<32>(n).to_string().substr(
            bitset<32>(n).to_string().find('1'));
    }

    static bool compare(const string& a, const string& b) {
        return a + b > b + a;
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaries;
        for (int num : nums) {
            binaries.push_back(decimalToBin(num));
        }

        sort(binaries.begin(), binaries.end(), compare);

        string concatenatedBinary;
        for (const string& binary : binaries) {
            concatenatedBinary += binary;
        }
        return stoll(concatenatedBinary, nullptr, 2);
    }
};