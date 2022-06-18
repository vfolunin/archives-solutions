class MyCalendar {
    set<pair<int, int>> segments;
    
    static bool intersects(int l, int r, set<pair<int, int>>::iterator it) {
        auto [l2, r2] = *it;
        return l < r2 && l2 < r;
    }
    
public:    
    bool book(int l, int r) {
        auto it = segments.lower_bound({ l, r });
        if (it != segments.end() && intersects(l, r, it) || 
            it != segments.begin() && intersects(l, r, prev(it)))
            return 0;
        
        segments.insert({ l, r });
        return 1;
    }
};