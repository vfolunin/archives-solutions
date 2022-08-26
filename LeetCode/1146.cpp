class SnapshotArray {
    vector<vector<pair<int, int>>> a;
    int timer = 0;
    
public:
    SnapshotArray(int size) : a(size, vector<pair<int, int>>(1)) {}
    
    void set(int index, int val) {
        if (a[index].back().first < timer)
            a[index].push_back({ timer, val });
        else
            a[index].back().second = val;
    }
    
    int snap() {
        return timer++;
    }
    
    int get(int index, int time) {
        return prev(upper_bound(a[index].begin(), a[index].end(), make_pair(time, (int)1e9)))->second;
    }
};