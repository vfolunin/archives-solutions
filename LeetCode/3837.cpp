class Solution {
public:
    vector<int> delayedCount(vector<int> &a, int gap) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[i] = pos[a[i]].end() - upper_bound(pos[a[i]].begin(), pos[a[i]].end(), i + gap);
        return res;
    }
};