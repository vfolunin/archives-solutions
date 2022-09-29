class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    vector<long long> maximumSegmentSum(vector<int> &a, vector<int> &queries) {
        vector<long long> p = { a.begin(), a.end() };
        partial_sum(p.begin(), p.end(), p.begin());
        
        set<pair<int, int>> segments = { { 0, a.size() - 1 } };
        multiset<long long> sums = { 0, getSum(p, 0, p.size() - 1) };
        vector<long long> res(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            auto it = prev(segments.lower_bound({ queries[i], 1e9 }));
            auto [l, r] = *it;
            segments.erase(it);
            sums.erase(sums.find(getSum(p, l, r)));
            
            if (l < queries[i]) {
                segments.insert({ l, queries[i] - 1 });
                sums.insert(getSum(p, l, queries[i] - 1));
            }
            if (queries[i] < r) {
                segments.insert({ queries[i] + 1, r });
                sums.insert(getSum(p, queries[i] + 1, r));
            }
            
            res[i] = *sums.rbegin();
        }
        
        return res;
    }
};