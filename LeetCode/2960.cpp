class Solution {
public:
    int countTestedDevices(vector<int> &a) {
        int res = 0;
        for (int value : a)
            res += value > res;
        return res;
    }
};