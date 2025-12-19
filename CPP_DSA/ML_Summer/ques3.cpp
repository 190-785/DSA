#include <iostream>
#include <vector>
#include <stack>
#include <numeric> // For accumulate if needed, though not used here.
using namespace std;
// The Solution class containing the logic
class Solution {
public:
    long long stackingMoney(vector<int> &A);
};

/**
 * @brief Calculates the sum of (max - min) over all subarrays of A.
 * * This function uses a monotonic stack approach to find the contribution of each element
 * to the total sum of maximums and the total sum of minimums across all subarrays.
 * The overall complexity is O(N), which is efficient for the given constraints.
 * * @param A The input integer array.
 * @return A long long integer representing the total sum.
 */
long long Solution::stackingMoney(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    
    vector<int> l_max(n), r_max(n);
    vector<int> l_min(n), r_min(n);
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && A[s.top()] < A[i]) {
            s.pop();
        }
        
        l_max[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    
    while (!s.empty()) s.pop();
    
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && A[s.top()] <= A[i]) {
            s.pop();
        }
        
        r_max[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    
    while (!s.empty()) s.pop();
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && A[s.top()] > A[i]) {
            s.pop();
        }
        
        l_min[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    
    while (!s.empty()) s.pop();
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        r_min[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    
    long long max_sum = 0;
    long long min_sum = 0;
        
    for (int i = 0; i <n; i++) {
        long long count_max = (long long) (i - l_max[i]) * (r_max[i] - i);
        max_sum += (long long) A[i] * count_max;
        
        long long count_min = (long long) (i - l_min[i]) * (r_min[i] - i);
        min_sum += (long long) A[i] * count_min;
    }
    
    return max_sum - min_sum;
}
// --- Main function to run and test the code ---
int main() {
    Solution sol;

    // Example 1
    vector<int> A1 = {1, 2, 3};
    long long result1 = sol.stackingMoney(A1);
    cout << "Input: [1, 2, 3]" << endl;
    cout << "Output: " << result1 << endl; // Expected: 4
    cout << "--------------------" << endl;

    // Example 2
    vector<int> A2 = {1, 1, 1};
    long long result2 = sol.stackingMoney(A2);
    cout << "Input: [1, 1, 1]" << endl;
    cout << "Output: " << result2 << endl; // Expected: 0
    cout << "--------------------" << endl;

    return 0;
}