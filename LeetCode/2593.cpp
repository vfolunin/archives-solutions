class Solution {
public:
    long long findScore(vector<int> &a) {
        set<pair<int, int>> pairs;
        for (int i = 0; i < a.size(); i++)
            pairs.insert({ a[i], i });
        
        vector<int> marked(a.size());        
        long long res = 0;
        
        for (auto &[value, i] : pairs) {
            if (marked[i])
                continue;
            
            res += value;
            
            for (int j : { i - 1, i, i + 1 })
                if (0 <= j && j < a.size())
                    marked[j] = 1;
        }
        
        return res;
    }
};