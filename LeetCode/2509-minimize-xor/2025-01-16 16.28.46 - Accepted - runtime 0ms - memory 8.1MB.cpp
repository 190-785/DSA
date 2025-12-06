class Solution {
public:
    int count_bits(int num) {
        int res = 0;
        while (num > 0) {
            res += num & 1;
            num >>= 1;
        }
        return res;
    }

    int minimizeXor(int num1, int num2) {
        int count1 = count_bits(num1);
        int count2 = count_bits(num2);
        int x = num1;
        int i = 0;
        while (count1 != count2) {
            if (count1 < count2 && !(x & (1 << i))) {
                count1++;
                x |= (1 << i);
            } else if (count1 > count2 && (x & (1 << i))) {
                count1--;
                x &= ~(1 << i);
            }
            i++;
        }
        return x;
    }
};
