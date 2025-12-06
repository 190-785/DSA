class Solution {
public:
    void qs(vector<int>& nums, int low, int high) {
        if (low < high) {
            int partition = f(nums, low, high);
            qs(nums, low, partition - 1);
            qs(nums, partition + 1, high);
        }
    }

    int f(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (arr[i] <= pivot && i < high) {
                i++;
            }
            while (arr[j] > pivot && j > low) {
                j--;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }

    void sortColors(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
    }
};
