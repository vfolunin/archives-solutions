class Solution {
public:
    vector<int> findPermutation(string &s) {
        vector<int> res(s.size() + 1);
        iota(res.begin(), res.end(), 1);

        for (int l = 0, r = 0; l < s.size(); l = r) {
            if (s[r] == 'I') {
                r++;
            } else {
                while (r < s.size() && s[r] == 'D')
                    r++;
                reverse(res.begin() + l, res.begin() + r + 1);
            }
        }
        
        return res;
    }
};