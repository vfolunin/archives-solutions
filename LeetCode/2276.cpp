struct SegmentSet {
    set<pair<int, int>> segments;
    int size = 0;
    
    static bool intersect(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first <= b.second && b.first <= a.second;
    }
    
    void insert(pair<int, int> segment) {
        auto it = segments.lower_bound(segment);
        if (it != segments.begin() && intersect(*prev(it), segment))
            it--;
        
        while (it != segments.end() && intersect(*it, segment)) {
            segment.first = min(segment.first, it->first);
            segment.second = max(segment.second, it->second);
            size -= it->second - it->first + 1;
            it = segments.erase(it);
        }
        
        size += segment.second - segment.first + 1;
        segments.insert(segment);
    }
};

class CountIntervals {
    SegmentSet segmentSet;
    
public:    
    void add(int l, int r) {
        segmentSet.insert({ l, r });
    }
    
    int count() {
        return segmentSet.size;
    }
};