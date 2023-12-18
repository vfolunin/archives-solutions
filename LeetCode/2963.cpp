class Solution {
    bool intersect(pair<int, int> &a, pair<int, int> &b) {
        return a.first <= b.second && b.first <= a.second;
    }
    
    pair<int, int> combine(pair<int, int> &a, pair<int, int> &b) {
        return { min(a.first, b.first), max(a.second, b.second) };
    }

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int numberOfGoodPartitions(vector<int> &a) {
        unordered_map<int, int> l, r;
        for (int i = 0; i < a.size(); i++) {
            if (!l.count(a[i]))
                l[a[i]] = i;
            r[a[i]] = i;
        }

        vector<pair<int, int>> segments;
        for (auto &[value, _] : l)
            segments.push_back({ l[value], r[value] });
        sort(segments.begin(), segments.end());

        vector<pair<int, int>> mergedSegments;
        for (auto &segment : segments) {
            while (!mergedSegments.empty() && intersect(mergedSegments.back(), segment)) {
                segment = combine(mergedSegments.back(), segment);
                mergedSegments.pop_back();
            }
            mergedSegments.push_back(segment);
        }

        return binPow(2, mergedSegments.size() - 1, 1e9 + 7);
    }
};