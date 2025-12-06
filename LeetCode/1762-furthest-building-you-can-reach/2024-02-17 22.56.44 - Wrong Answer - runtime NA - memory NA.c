int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders) {
    int i;
    int count = 0;
    int temp[heightsSize];
    for (i = 1; i < heightsSize; i++) {

        if (heights[i] < heights[i - 1]) {
            count++;
        } else if (ladders != 0) {
            if ((heights[i] - heights[i - 1]) > bricks / 2) {
                ladders--;
                count++;
            } else {
                if (bricks >= (heights[i] - heights[i - 1])) {
                    bricks -= (heights[i] - heights[i - 1]);
                    count++;
                }
            }}
            else {
                if (bricks >= (heights[i] - heights[i - 1])) {
                    bricks -= (heights[i] - heights[i - 1]);
                    count++;
                }
            }
        if(temp[i]==temp[i-1]){
            break;
        }
        else{
        temp[i-1]=count;
        }
    }

    return count;
}