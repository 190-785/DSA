class Solution {
public:
    void reverseString(vector<char>& s) {
        int size;
        size=s.size();
        int n=size-1;
        for(int i=0;i<size/2;i++){
            std::swap(s[i], s[n]);
            n--;
        }
    }
};