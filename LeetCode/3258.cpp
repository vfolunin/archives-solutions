class Solution {
public:
    int countKConstraintSubstrings(string &s, int limit) {
        vector<int> count(2);
        int res = 0;

        for (int l = 0, r = 0; r < s.size(); r++) {
            count[s[r] - '0']++;
            while (count[0] > limit && count[1] > limit) {
                count[s[l] - '0']--;
                l++;
            }
            res += r - l + 1;
        }

        return res;
    }
};