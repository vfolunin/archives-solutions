class Solution {
public:
    int minCostToMoveChips(vector<int> &a) {
        vector<int> count(2);
        for (int value : a)
            count[value % 2]++;
        return min(count[0], count[1]);
    }
};