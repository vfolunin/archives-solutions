class Solution {
public:
    int minOperations(string s) {
        int res0 = 0, res1 = 0;
        for (int i = 0; i < s.size(); i++) {
            res0 += s[i] % 2 == i % 2;
            res1 += s[i] % 2 != i % 2;
        }
        return min(res0, res1);
    }
};