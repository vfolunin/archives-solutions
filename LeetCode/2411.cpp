class Solution {
public:
    vector<int> smallestSubarrays(vector<int> &a) {
        vector<vector<int>> pos(30);
        for (int i = 0; i < a.size(); i++)
            for (int bit = 0; bit < 30; bit++)
                if (a[i] & (1 << bit))
                    pos[bit].push_back(i);
        
        vector<int> res(a.size(), 1);
        for (int i = 0; i < res.size(); i++) {
            for (int bit = 0; bit < 30; bit++) {
                auto it = lower_bound(pos[bit].begin(), pos[bit].end(), i);
                if (it != pos[bit].end())
                    res[i] = max(res[i], *it - i + 1);
            }
        }
        return res;
    }
};