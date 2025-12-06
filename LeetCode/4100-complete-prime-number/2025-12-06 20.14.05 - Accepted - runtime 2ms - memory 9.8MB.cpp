class Solution {
public:
    bool isPrime(int x) {
        if (x == 1)
            return false;
        if (x == 3 || x == 2)
            return true;
        if (x % 2 == 0 || x % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(x) + 1; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        // Ques is done by me
        string str = to_string(num);
        int n = str.size();
        // Simple check of all suffix and all the prefix
        for (int i = 0; i < n; i++) {
            int prefix = stoi(str.substr(0, i + 1));
            if (!isPrime(prefix))
                return false;
            int suffix = stoi(str.substr(n - (i + 1), i + 1));
            if (!isPrime(suffix))
                return false;
        }
        return true;
    }
};