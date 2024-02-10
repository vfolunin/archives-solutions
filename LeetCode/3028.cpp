class Solution {
public:
    int returnToBoundaryCount(vector<int> &a) {
        int sum = 0, res = 0;
        for (int value : a) {
            sum += value;
            res += !sum;
        }
        return res;
    }
};