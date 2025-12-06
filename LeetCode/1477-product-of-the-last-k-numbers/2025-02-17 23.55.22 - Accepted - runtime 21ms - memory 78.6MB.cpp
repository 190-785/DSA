class ProductOfNumbers {
public:
    vector<long long> prefix;
    ProductOfNumbers() { prefix.push_back(1); }
    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            long long last = prefix.back();
            prefix.push_back(last * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n)
            return 0;
        return static_cast<int>(prefix[n - 1] / prefix[n - k - 1]);
    }
};
