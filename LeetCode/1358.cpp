class Solution {
public:
    int numberOfSubstrings(string &s) {
        vector<int> seen(3, -1);
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            seen[s[i] - 'a'] = i;
            int from = *min_element(seen.begin(), seen.end());
            res += from + 1;
        }
        
        return res;
    }
};