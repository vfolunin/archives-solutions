class Solution {
public:
    int getMaximumConsecutive(vector<int> &a) {
        sort(a.begin(), a.end());
        int res = 1;
        for (int value : a) {
            if (value <= res)
                res += value;
            else
                break;
        }
        return res;
    }
};