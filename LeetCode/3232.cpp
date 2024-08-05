class Solution {
public:
    bool canAliceWin(vector<int> &a) {
        vector<int> sum(2);
        for (int value : a)
            sum[value > 9] += value;
        return sum[0] != sum[1];
    }
};