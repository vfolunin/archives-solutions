class Solution {
public:
    int partitionString(string &s) {
        int res = 1;
        vector<int> used(26);
        for (char c : s) {
            if (used[c - 'a']) {
                res++;
                used.assign(26, 0);
            }
            used[c - 'a'] = 1;
        }
        return res;
    }
};