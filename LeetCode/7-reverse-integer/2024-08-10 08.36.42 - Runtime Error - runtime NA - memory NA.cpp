class Solution {
public:
    int reverse(int x) {
        int temp=0;
        int result=0;
        while(x!=0){
            temp=x%10;
            result=(result*10)+temp;
            x/=10;
        }
        return result;
    }
};