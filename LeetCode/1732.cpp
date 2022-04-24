class Solution {
public:
    int largestAltitude(vector<int> &a) {
        int cur = 0, res = 0;
        for (int value : a) {
            cur += value;
            res = max(res, cur);
        }
        return res;
    }
};