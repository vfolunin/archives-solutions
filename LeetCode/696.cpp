class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroupSize = 0, groupSize = 1, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                groupSize++;
            } else {
                res += min(prevGroupSize, groupSize);
                prevGroupSize = groupSize;
                groupSize = 1;
            }
        }
        res += min(prevGroupSize, groupSize);
        return res;
    }
};