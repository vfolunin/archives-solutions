class Solution {
public:
    int minFlips(string target) {
        int res = target[0] - '0';
        for (int i = 1; i < target.size(); i++)
            res += target[i - 1] != target[i];
        return res;
    }
};