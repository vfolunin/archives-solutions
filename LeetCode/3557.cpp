class Solution {
public:
    int maxSubstrings(string &s) {
        vector<vector<int>> pos(26);
        vector<int> res(s.size());

        for (int i = 0; i < s.size(); i++) {
            if (i)
                res[i] = res[i - 1];
            
            vector<int> &p = pos[s[i] - 'a'];

            int j = (int)p.size() - 1;
            while (0 <= j && i - p[j] < 3)
                j--;
                
            if (0 <= j)
                res[i] = max(res[i], (p[j] ? res[p[j] - 1] : 0) + 1);

            p.push_back(i);
        }

        return res.back();
    }
};