class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size();
        int bsize = b.size();
        char carry = '0';
        string res;
        int i = asize - 1, j = bsize - 1;
        
        while (i >= 0 && j >= 0) {
            if (a[i] == '0' && b[j] == '0') {
                res.insert(res.begin(), carry);
                carry = '0';
            } else if ((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0')) {
                if (carry == '1') {
                    res.insert(res.begin(), '0');
                    carry = '0';
                } else {
                    res.insert(res.begin(), '1');
                }
            } else {
                if (carry == '1') {
                    res.insert(res.begin(), '1');
                } else {
                    res.insert(res.begin(), '0');
                    carry = '1';
                }
            }
            i--;
            j--;
        }
        
        while (i >= 0) {
            if (carry == '0') {
                res.insert(res.begin(), a[i]);
            } else {
                if (a[i] == '0') {
                    res.insert(res.begin(), carry);
                    carry = '0';
                } else {
                    res.insert(res.begin(), '0');
                }
            }
            i--;
        }
        
        while (j >= 0) {
            if (carry == '0') {
                res.insert(res.begin(), b[j]);
            } else {
                if (b[j] == '0') {
                    res.insert(res.begin(), carry);
                    carry = '0';
                } else {
                    res.insert(res.begin(), '0');
                }
            }
            j--;
        }
        
        if (carry == '1') res.insert(res.begin(), carry);
        return res;
    }
};
