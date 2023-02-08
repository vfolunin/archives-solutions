class Solution {
public:
    long long numberOfSubstrings(string &s) {
        vector<long long> count(26);
        long long res = 0;

        for (char c : s) {
            count[c - 'a']++;
            res += count[c - 'a'];
        }

        return res;
    }
};