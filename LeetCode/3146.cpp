class Solution {
public:
    int findPermutationDifference(string &a, string &b) {
        int res = 0;
        for (char c = 'a'; c <= 'z'; c++)
            res += abs((int)a.find(c) - (int)b.find(c));
        return res;
    }
};