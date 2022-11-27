class RangeModule {
    static const int INF = 2e9;
    set<pair<int, int>> segments = { { -INF, -INF }, { INF, INF } };

    bool intersect(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first <= b.second && b.first <= a.second;
    }

    bool contain(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first <= b.first && b.second <= a.second;
    }

public:
    void addRange(int l, int r) {
        pair<int, int> segment = { l, r };

        for (auto it = segments.begin(); it != segments.end(); ) {
            if (intersect(segment, *it)) {
                segment = { min(segment.first, it->first), max(segment.second, it->second) };
                it = segments.erase(it);
            } else {
                it++;
            }
        }

        segments.insert(segment);
    }

    bool queryRange(int l, int r) {
        auto it = segments.lower_bound({ l, l });
        if (it->first == l)
            return it->second >= r;
        else
            return prev(it)->second >= r;
    }

    void removeRange(int l, int r) {
        pair<int, int> segment = { l, r };
        set<pair<int, int>> newSegments;

        for (auto it = segments.begin(); it != segments.end(); ) {
            if (contain(segment, *it)) {
                it = segments.erase(it);
            } else if (intersect(segment, *it)) {
                if (it->first < segment.first)
                    newSegments.insert({ it->first, segment.first });
                if (segment.second < it->second)
                    newSegments.insert({ segment.second, it->second });
                it = segments.erase(it);
            } else {
                it++;
            }
        }

        segments.insert(newSegments.begin(), newSegments.end());
    }
};
