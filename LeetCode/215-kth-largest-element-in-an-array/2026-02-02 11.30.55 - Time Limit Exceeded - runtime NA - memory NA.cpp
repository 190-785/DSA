class Solution {
public:
    int partition(vector<int>& arr, int low, int high, int pivot) {
        int pivotIndex = -1;
        for (int i = low; i <= high; i++) {
            if (arr[i] == pivot) {
                pivotIndex = i;
                break;
            }
        }
        swap(arr[pivotIndex], arr[high]);
        int i = low;
        for (int j = low; j < high; j++) {
            if (arr[j] <= arr[high]) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    int findMedian(vector<int>& arr, int low, int high) {
        vector<int> temp(arr.begin() + low, arr.begin() + high + 1);
        sort(temp.begin(), temp.end());
        return temp[temp.size() / 2];
    }

    int medianOfMedians(vector<int>& arr, int low, int high, int k) {
        if (high - low + 1 <= 5) {
            sort(arr.begin() + low, arr.begin() + high + 1);
            return arr[low + k - 1];
        }

        int n = high - low + 1;
        vector<int> medians((n + 4) / 5);
        for (int i = 0; i < medians.size(); i++) {
            int subLow = low + i * 5;
            int subHigh = min(subLow + 4, high);
            medians[i] = findMedian(arr, subLow, subHigh);
        }

        int medianOfMedian = medianOfMedians(medians, 0, medians.size() - 1,
                                             (medians.size() + 1) / 2);
        int pivotIndex = partition(arr, low, high, medianOfMedian);
        int length = pivotIndex - low + 1;

        if (length == k) {
            return arr[pivotIndex];
        } else if (k < length) {
            return medianOfMedians(arr, low, pivotIndex - 1, k);
        } else {
            return medianOfMedians(arr, pivotIndex + 1, high, k - length);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return medianOfMedians(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
};
