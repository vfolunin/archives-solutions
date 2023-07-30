class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &a, int limit) {
        int res = 0;
        for (int value : a)
            res += value >= limit;
        return res;
    }
};