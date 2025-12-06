class Solution {
public:
    int BinToDec(string binary) {
        int ans = 0;
        for (int i = binary.size() - 1; i >= 0; i--) {
            if (binary[i] == '1')
                ans += pow(2, 31 - i);
        }
        return ans;
    }

    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        string binaryOfnum1 = bitset<32>(num1).to_string();
        for (int i = 0; i < binaryOfnum1.size(); i++) {
            if (binaryOfnum1[i] == '1' && setBits > 0)
                setBits--;
            else
                binaryOfnum1[i] = '0';
        }
        int ind = binaryOfnum1.size();
        while (setBits > 0 && ind >= 0) {
            if (binaryOfnum1[ind] == '0') {
                binaryOfnum1[ind] = '1';
                setBits--;
            } else
                ind--;
        }
        return BinToDec(binaryOfnum1);
    }
};