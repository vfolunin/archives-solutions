struct SegmentSet {
    set<pair<int, int>> segments;
    multiset<int> sizes;
    
    void add(int x) {
        int l = x, r = x;
        
        auto rIt = segments.lower_bound({ x, 0 });
        if (rIt != segments.end() && r + 1 == rIt->first) {
            r += rIt->second;
            sizes.erase(sizes.find(rIt->second));
            segments.erase(rIt);
        }
        
        auto lIt = segments.lower_bound({ x, 0 });
        if (lIt != segments.begin()) {
            lIt--;
            if (lIt->first + lIt->second == l) {
                l -= lIt->second;
                sizes.erase(sizes.find(lIt->second));
                segments.erase(lIt);
            }
        }
        
        segments.insert({ l, r - l + 1 });
        sizes.insert(r - l + 1);
    }
};

class Solution {
public:
    int findLatestStep(vector<int> &a, int size) {
        SegmentSet segments;
        int res = -1;
        
        for (int i = 0; i < a.size(); i++) {
            segments.add(a[i]);
            if (segments.sizes.count(size))
                res = i + 1;
        }
        
        return res;
    }
};