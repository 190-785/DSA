class SnapshotArray {
public:
    int snapId;
    vector<vector<pair<int,int>>> historicalData;
    SnapshotArray(int length) {
        snapId=0;
        historicalData.resize(length);
        for(int i=0;i<length;i++){
            historicalData[i].push_back(make_pair(0,0));
        }
    }
    
    void set(int index, int val) {
        historicalData[index].push_back(make_pair(snapId,val));
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it=upper_bound(historicalData[index].begin(),historicalData[index].end(),make_pair(snap_id,INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */