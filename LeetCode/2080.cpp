class RangeFreqQuery {
    unordered_map<int, vector<int>> pos;
    
public:
    RangeFreqQuery(vector<int> &a) {
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
    }
    
    int query(int l, int r, int value) {
        auto from = lower_bound(pos[value].begin(), pos[value].end(), l);
        auto to = upper_bound(pos[value].begin(), pos[value].end(), r);
        return to - from;
    }
};