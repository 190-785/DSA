class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0, k = 0;
        while (j < m + n && k < n) {
            if (nums1[j] == 0) {
                nums1[j] = nums2[k];
                j++;
                k++;
            } else if (nums1[j] > nums2[k]) {
                swap(nums1[j], nums2[k]);
                j++;
            } else {
                j++;
            }
        }
    }
};