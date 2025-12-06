int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int i,j,wealth,maxwealth=0;
    for(i=0;i<accountsSize;i++){
        wealth=0;
        for(j=0;j<accountsColSize[i];j++){
            wealth+=accounts[i][j];
        }
        if(maxwealth<wealth){
            maxwealth=wealth;
        }
    }
    return maxwealth;
}