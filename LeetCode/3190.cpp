class Solution {
public:
    int minimumOperations(vector<int> &a) {
        int res = 0;
        for (int value : a)
            res += value % 3 != 0;
        return res;
    }
};