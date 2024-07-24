class Solution {
public:
    int maxOperations(string &s) {
        int zeroBlocks = 0, res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1')
                res += zeroBlocks;
            else if (i + 1 == s.size() || s[i + 1] == '1')
                zeroBlocks++;
        }
        return res;
    }
};