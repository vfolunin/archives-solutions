class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        vector<int> l(security.size(), 1);
        for (int i = 1; i < l.size(); i++)
            if (security[i - 1] >= security[i])
                l[i] += l[i - 1];
        
        vector<int> r(security.size(), 1);
        for (int i = (int)r.size() - 2; i >= 0; i--)
            if (security[i] <= security[i + 1])
                r[i] += r[i + 1];
        
        vector<int> res;
        for (int i = 0; i < security.size(); i++)
            if (l[i] > time && r[i] > time)
                res.push_back(i);
        return res;
    }
};