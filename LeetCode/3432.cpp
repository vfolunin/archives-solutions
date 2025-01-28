class Solution {
public:
    int countPartitions(vector<int> &a) {
        int l = 0, r = accumulate(a.begin(), a.end(), 0);
        int res = 0;
        for (int value : a) {
            l += value;
            r -= value;
            res += r && abs(l - r) % 2 == 0;
        }
        return res;
    }
};