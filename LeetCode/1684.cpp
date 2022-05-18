class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int res = 0;
        
        for (string &word : words) {
            bool ok = 1;
            for (char c : word) {
                if (!allowedSet.count(c)) {
                    ok = 0;
                    break;
                }
            }
            res += ok;
        }
        
        return res;
    }
};