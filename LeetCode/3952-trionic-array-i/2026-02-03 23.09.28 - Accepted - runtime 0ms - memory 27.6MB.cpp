class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        int p = -1, q = -1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1])
                return false;
            if (state == 0) {
                if (nums[i] < nums[i + 1]) {
                    p = i + 1;
                    continue;
                } else {
                    if (p == -1){
                        //cout<<"1";
                        return false;
                    }
                    state++;
                }
            }  if (state == 1) {
                if (nums[i] > nums[i + 1]) {
                    q = i + 1;
                    continue;
                } else {
                    if (q == -1){
                        //cout<<"2";
                        return false;
                    }
                    state++;
                }
            } if(state==2) {
                if (nums[i] > nums[i + 1]){
                    //cout<<"3";
                    return false;
                }
            }
        }
       // cout << p << " " << q;
        return (p == -1 || q == -1 || q == n - 1 || p == n - 1)
                   ? false
                   : true;
    }
};