class Solution {
public:
    int longestIdealString(string &s, int k) {
        vector<int> length(26);
        
        for (char c : s) {
            int l = 0;
            for (char p = max<char>('a', c - k); p <= 'z' && p <= c + k; p++)
                l = max(l, length[p - 'a'] + 1);
            length[c - 'a'] = l;
        }
        
        return *max_element(length.begin(), length.end());
    }
};