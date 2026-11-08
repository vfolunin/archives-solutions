class Solution {
public:
    long long countValidSubstrings(string &s) {
        long long res = 0;
        vector<int> index(3, -1);
        for (int i = 0; i < s.size(); i++) {
            index[s[i] - 'a'] = (s[i] == 'a' ? i : index[s[i] - 'a' - 1]);
            res += i - index[2];
        }
        return res;
    }
};