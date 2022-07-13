class Solution {
    struct Item {
        int ai, bi, sum;
        
        bool operator < (const Item &that) const {
            if (sum != that.sum)
                return sum < that.sum;
            if (ai != that.ai)
                return ai < that.ai;
            return bi < that.bi;
        }
    };
    
public:
    vector<vector<int>> kSmallestPairs(vector<int> &a, vector<int> &b, int k) {
        set<Item> q = { { 0, 0, a[0] + b[0] } };
        
        vector<vector<int>> res;
        while (res.size() < k && !q.empty()) {
            auto [ai, bi, sum] = *q.begin();
            q.erase(q.begin());
            
            res.push_back({ a[ai], b[bi] });
            if (ai + 1 < a.size())
                q.insert({ ai + 1, bi, a[ai + 1] + b[bi] });
            if (bi + 1 < b.size())
                q.insert({ ai, bi + 1, a[ai] + b[bi + 1] });
        }
        return res;
    }
};