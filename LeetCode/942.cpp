class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l = 0, r = 0;
        vector<int> res = { 0 };
        
        for (char c : s) {
            if (c == 'D')
                res.push_back(--l);
            else
                res.push_back(++r);
        }
        
        for (int &value : res)
            value -= l;
        
        return res;
    }
};