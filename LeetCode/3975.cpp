struct SegmentSet {
    set<pair<int, int>> segments;

    void insert(int l, int r) {
        auto it = segments.lower_bound({ l, l });
        if (it != segments.begin() && l <= prev(it)->second + 1)
            it--;

        while (it != segments.end() && l <= it->second + 1 && it->first <= r + 1) {
            l = min(l, it->first);
            r = max(r, it->second);
            it = segments.erase(it);
        }

        segments.insert({ l, r });
    }

    void erase(int l, int r) {
        auto it = segments.lower_bound({ l, l });
        if (it != segments.begin() && l <= prev(it)->second + 1)
            it--;
        
        if (it == segments.end() || r < it->first)
            return;

        auto [sl, sr] = *it;
        while (it != segments.end() && l <= it->second + 1 && it->first <= r + 1) {
            sr = it->second;
            it = segments.erase(it);
        }

        if (sl < l)
            segments.insert({ sl, l - 1 });
        if (r < sr)
            segments.insert({ r + 1, sr });
    }
};

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>> &segments, int l, int r) {
        SegmentSet segmentSet;
        for (vector<int> &segment : segments)
            segmentSet.insert(segment[0], segment[1]);
        segmentSet.erase(l, r);

        vector<vector<int>> res;
        for (auto &[l, r] : segmentSet.segments)
            res.push_back({ l, r });
        return res;
    }
};