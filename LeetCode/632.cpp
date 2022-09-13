class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &a) {
        set<pair<int, int>> window;
        vector<int> indexes(a.size());
        for (int i = 0; i < a.size(); i++)
            window.insert({ a[i][0], i });
        
        vector<int> res = { window.begin()->first, prev(window.end())->first };
        
        while (1) {
            auto [_, i] = *window.begin();
            window.erase(window.begin());
            
            if (indexes[i] == a[i].size() - 1)
                break;
            
            indexes[i]++;
            window.insert({ a[i][indexes[i]], i });
            
            int l = window.begin()->first;
            int r = prev(window.end())->first;
            if (res[1] - res[0] > r - l)
                res = { l, r };
        }
        
        return res;
    }
};