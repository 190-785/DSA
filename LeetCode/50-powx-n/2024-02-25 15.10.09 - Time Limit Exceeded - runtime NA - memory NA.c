double myPow(double x, int n) {
    int i;
    double power = x;
    if (n > 0) {
        for (i = 0; i < n - 1; i++) {
            power *= x;
        }
        return power;
    } else if (n < 0) {
        for (i = 0; i > n - 1; i--) {
            power /= x;
        }
        return power;
    } else {
        return 1;
    }
}