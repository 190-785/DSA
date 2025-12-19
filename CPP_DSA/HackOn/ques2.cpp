#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <limits>

long long evaluate_expression(const std::string& expr_str) {
    std::istringstream iss(expr_str);
    long long current_value;
    long long next_value;
    char operation;

    if (expr_str.empty()) return -1;

    if (!(iss >> current_value)) {
        return -1; 
    }

    while (iss >> operation) {
        if (operation != '+' && operation != '-') {
            return -1; 
        }
        
        if (!(iss >> next_value)) {
            return -1; 
        }

        if (operation == '+') {
            current_value += next_value;
        } else { 
            current_value -= next_value;
        }
    }
    
    iss.clear(); 
    std::string remaining_junk;
    if (iss >> remaining_junk) {
        return -1; 
    }

    return current_value;
}

long long calculate_gcd(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long calculate_lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    long long common_divisor = calculate_gcd(a, b);
    if (common_divisor == 0) {
         return 0;
    }
    
    long long abs_a = std::abs(a);
    long long abs_b = std::abs(b);
    
    return (abs_a / common_divisor) * abs_b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    long long x_eval = evaluate_expression(str1);
    long long y_eval = evaluate_expression(str2);

    std::cout << x_eval << std::endl;
    std::cout << y_eval << std::endl;    if (x_eval == -1 || y_eval == -1) {
        return 0;
    }

    // Special case: if both values are negative, return 0
    if (x_eval < 0 && y_eval < 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long x_prime = std::abs(x_eval);
    long long y_prime = std::abs(y_eval);

    if (x_prime == 0 || y_prime == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    if (x_prime == y_prime) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long optimal_N = 0;
    long long min_lcm_found = calculate_lcm(x_prime, y_prime);

    long long diff_abs = std::abs(x_prime - y_prime);
    std::vector<long long> divisors;
    for (long long i = 1; i * i <= diff_abs; ++i) {
        if (diff_abs % i == 0) {
            divisors.push_back(i);
            if (i * i != diff_abs) {
                divisors.push_back(diff_abs / i);
            }
        }
    }
    if (diff_abs == 0 && x_prime != y_prime) {}
    else if (diff_abs == 0) {
    }

    for (long long d_i : divisors) {
        if (d_i == 0) continue;
        long long n_candidate = (d_i - (x_prime % d_i)) % d_i;
        
        long long current_val_x = x_prime + n_candidate;
        long long current_val_y = y_prime + n_candidate;
        long long current_lcm = calculate_lcm(current_val_x, current_val_y);

        if (current_lcm < min_lcm_found) {
            min_lcm_found = current_lcm;
            optimal_N = n_candidate;
        } else if (current_lcm == min_lcm_found) {
            optimal_N = std::min(optimal_N, n_candidate);
        }
    }

    std::cout << optimal_N << std::endl;

    return 0;
}
