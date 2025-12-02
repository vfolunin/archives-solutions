class Solution {
public:
    int maxDistinct(string &s) {
        vector<int> has(26);
        for (char c : s)
            has[c - 'a'] = 1;
        return count(has.begin(), has.end(), 1);
    }
};