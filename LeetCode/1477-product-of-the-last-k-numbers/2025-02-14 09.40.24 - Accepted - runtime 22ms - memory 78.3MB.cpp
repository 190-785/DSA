class ProductOfNumbers {
public:
    vector<int>prefix;
    int size = 0;
    int lastOccuranceOfZero = -1;
    ProductOfNumbers() {
        prefix.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0){
            size++;
            prefix.push_back(1);
            lastOccuranceOfZero = size;
        }
        else{
            prefix.push_back(prefix[size]*num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(lastOccuranceOfZero > size-k)return 0;
        return prefix[size]/prefix[size-k];
        
    }
};