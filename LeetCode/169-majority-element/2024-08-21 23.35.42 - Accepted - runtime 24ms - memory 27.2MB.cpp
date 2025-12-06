class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> majMap;
        int n = nums.size();
        
        // Populate the map with element frequencies
        for(int i = 0; i < n; i++) {
            majMap[nums[i]]++;
        }
        
        // Find the majority element
        int majorityElement = nums[0];
        int maxCount = 0;
        
        for(auto& pair : majMap) {
            if(pair.second > maxCount) {
                maxCount = pair.second;
                majorityElement = pair.first;
            }
        }
        
        return majorityElement;
    }
};
