class Solution {
public:
    //Submitting for future referance
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<int> appear(pow(2,n),0);
        for(int i=0;i<n;i++){
            bitset<16> bits(nums[i]);
            unsigned long decimal_value = bits.to_ulong(); 
            appear[decimal_value]=1;
        }
        long long ans=0;
        for(int i=pow(2,n-1)+1;i<pow(2,n);i++){
            if(appear[i]==0){
                ans=i;
                break;
            }
        }

        bitset<16> binaryNumber(ans);
        string res="";
        cout<<binaryNumber<<endl;
        for(int i=16-n;i<16;i++){
            res+=binaryNumber[i];
        }
        cout<<res<<endl;
        cout<<typeid(binaryNumber).name();
        //string res=to_string(binaryNumber);
        //return res;
        return "";
    }
};