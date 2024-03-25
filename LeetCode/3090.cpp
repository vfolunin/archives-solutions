class Solution {
    bool isGood(string &s, int l, int r) {
        vector<int> count(26);
        for (int i = l; i <= r; i++)
            count[s[i] - 'a']++;
        return *max_element(count.begin(), count.end()) <= 2;
    }
    
public:
    int maximumLengthSubstring(string &s) {
        int res = 0;
        for (int l = 0; l < s.size(); l++)
            for (int r = l; r < s.size(); r++)
                if (isGood(s, l, r))
                    res = max(res, r - l + 1);
        return res;
    }
};