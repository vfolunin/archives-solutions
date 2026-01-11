class Solution {
public:
    long long countPairs(vector<string> &a) {
        unordered_map<string, int> count;
        long long res = 0;

        for (string &s : a) {
            int shift = (('a' - s[0]) % 26 + 26) % 26;
            for (char &c : s)
                c = (c + shift) % 26;
            res += count[s]++;
        }

        return res;
    }
};