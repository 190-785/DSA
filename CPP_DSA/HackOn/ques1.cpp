#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <iomanip>   // For std::fixed and std::setprecision

int main() {
    // Optimize C++ standard streams for faster I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> costs(n); // Game costs are integers.
    for (int i = 0; i < n; ++i) {
        std::cin >> costs[i];
    }

    int k;
    int max_limit_val; // Read maxLimit as an integer as per input format.
    std::cin >> k >> max_limit_val;
    
    // Convert max_limit_val to double for comparisons with summed costs.
    double max_limit = static_cast<double>(max_limit_val);

    // Sort the costs in ascending order to apply the greedy strategy.
    std::sort(costs.begin(), costs.end());

    int num_free_games = 0;
    // Calculate the maximum number of games that can be played for free.
    // K is guaranteed to be >= 1, so k+1 >= 2.
    // N is guaranteed to be >= 1.
    // Integer division gives floor(N / (K+1)).
    if (k + 1 > 0) { // Defensive check, though k >= 1 implies k+1 >= 2
        num_free_games = n / (k + 1); 
    }
    
    double total_cost_of_free_games = 0.0;
    // The 'num_free_games' cheapest games are chosen to be free.
    // These are costs[0] through costs[num_free_games-1].
    for (int i = 0; i < num_free_games; ++i) {
        total_cost_of_free_games += costs[i];
    }

    double total_cost_of_paid_games = 0.0;
    // The remaining games must be paid for.
    // These are costs from index 'num_free_games' to 'n-1'.
    for (int i = num_free_games; i < n; ++i) {
        total_cost_of_paid_games += costs[i];
    }
    
    double tax = 0.0;
    // Calculate tax if the total cost of free games exceeds maxLimit.
    // If total_cost_of_free_games is 0 (i.e., no free games), 
    // 0 > max_limit (which is >=1) will be false, so tax correctly remains 0.
    if (total_cost_of_free_games > max_limit) {
        tax = 0.10 * total_cost_of_free_games;
    }

    double final_min_cost = total_cost_of_paid_games + tax;

    // Output the result formatted to two decimal places.
    std::cout << std::fixed << std::setprecision(2) << final_min_cost << std::endl;

    return 0;
}