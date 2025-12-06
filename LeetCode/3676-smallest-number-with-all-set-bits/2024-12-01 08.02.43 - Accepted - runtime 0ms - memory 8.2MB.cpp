class Solution {
public:
    int smallestNumber(int n) {
        int num_bits = 0;
        int temp = n;
        
        while (temp > 0) {
            num_bits++;
            temp >>= 1;
        }
        int result = (1 << num_bits) - 1;
        
        return result;
    }
};
