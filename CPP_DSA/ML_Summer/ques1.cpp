#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    /**
     * @brief Finds the minimum radius needed for routers to cover all buildings.
     * @param A A vector of integers denoting the positions of buildings.
     * @param B A vector of integers denoting the positions of routers.
     * @return An integer denoting the minimum required coverage radius.
     */
    int findRadius(std::vector<int> &A, std::vector<int> &B);
};

using namespace std;

int Solution::findRadius(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    auto isPossible = [&](long long r) {
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            long long start = (long long)B[j] - r;
            long long end = (long long)B[j] + r;
            
            if (A[i] >= start && A[i] <= end) {
                while (i < A.size() && A[i] <= end) {
                    i++;
                }
                j++;
            } else {
                j++;
            }
        }
        return i >= A.size();
    };

    long long low = 0;
    long long high = 2e9;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}
// Main function to run and test the solution
int main() {
    Solution sol; // Create an instance of the Solution class

    // --- Example 1 ---
    std::vector<int> A1 = {5, 3, 7};
    std::vector<int> B1 = {5};
    std::cout << "Example 1 Output: " << sol.findRadius(A1, B1) << std::endl;
    std::cout << "Expected Output: 2" << std::endl;
    std::cout << "--------------------" << std::endl;

    // --- Example 2 ---
    std::vector<int> A2 = {1, 10};
    std::vector<int> B2 = {3, 7, 2};
    std::cout << "Example 2 Output: " << sol.findRadius(A2, B2) << std::endl;
    std::cout << "Expected Output: 3" << std::endl;
    std::cout << "--------------------" << std::endl;

    // --- Example 3 ---
    std::vector<int> A3 = {1, 2, 3, 4, 10};
    std::vector<int> B3 = {1};
    std::cout << "Example 3 Output: " << sol.findRadius(A3, B3) << std::endl;
    std::cout << "Expected Output: 9" << std::endl;
    std::cout << "--------------------" << std::endl;

    return 0;
}