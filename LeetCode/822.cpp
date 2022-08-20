class Solution {
public:
    int flipgame(vector<int> &a, vector<int> &b) {
        set<int> res({ a.begin(), a.end() });
        res.insert(b.begin(), b.end());
        
        for (int i = 0; i < a.size(); i++)
            if (a[i] == b[i])
                res.erase(a[i]);
        
        return !res.empty() ? *res.begin() : 0;
    }
};