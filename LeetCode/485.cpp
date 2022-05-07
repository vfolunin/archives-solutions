class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &a) {
        int cur = 0, res = 0;
        for (int x : a) {
            if (x)
                cur++;
            else
                cur = 0;
            res = max(res, cur);
        }
        return res;
    }
};