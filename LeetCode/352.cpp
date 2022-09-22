class SummaryRanges {
    set<pair<int, int>> segmentSet;
    
public:    
    void addNum(int value) {
        pair<int, int> segment = { value, value };
        
        auto r = segmentSet.lower_bound(segment);
        if (r->first == value)
            return;
        if (r != segmentSet.end() && value + 1 == r->first) {
            segment.second = r->second;
            segmentSet.erase(r);
        }
        
        auto l = segmentSet.lower_bound(segment);
        if (l != segmentSet.begin()) {
            l--;
            if (l->second >= value)
                return;
            if (l->second + 1 == value) {
                segment.first = l->first;
                segmentSet.erase(l);
            }
        }
        
        segmentSet.insert(segment);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto &[l, r] : segmentSet)
            res.push_back({ l, r });
        return res;
    }
};