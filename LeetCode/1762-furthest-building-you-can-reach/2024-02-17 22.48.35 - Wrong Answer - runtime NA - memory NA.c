int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders) {
    int i;
    int count = 0;
    int temp[heightsSize];

    for (i = 1; i < heightsSize; i++) {
        if (heights[i] <= heights[i - 1]) {
            count++;
        } else {
            int diff = heights[i] - heights[i - 1];
            if (diff <= bricks) {
                bricks -= diff;
                count++;
            } else if (ladders > 0) {
                ladders--;
                count++;
            } else {
                break;
            }
        }
    }

    return count;
}
