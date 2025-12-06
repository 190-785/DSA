int findCheapestPrice(int n, int** flights, int flightsSize,
                      int* flightsColSize, int src, int dst, int k) {
    int key[n][k + 2];
    const int Y = 1e9; 
    int i, j, a;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= k + 1; j++) {
            key[i][j] = Y;
        }
    }
    key[src][0] = 0;

    for (j = 1; j <= k + 1; j++) {
        for (i = 0; i < flightsSize; i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            key[to][j] = fmin(key[to][j], key[from][j - 1] + price);
        }
    }

    // Final answer
    if (key[dst][k + 1] == Y) {
        return -1;
    }
    return key[dst][k + 1];
}
