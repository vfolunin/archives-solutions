class Solution {
public:
    vector<int> decrypt(vector<int> &p, int k) {
        if (!k)
            return vector<int>(p.size());
        
        p.insert(p.end(), p.begin(), p.end());
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<int> res(p.size() / 2);
        for (int i = 0; i < res.size(); i++) {
            if (k > 0)
                res[i] = p[k + i] - p[i];
            else
                res[i] = p[res.size() - 1 + i] - p[res.size() - 1 + k + i];
        }
        return res;
    }
};