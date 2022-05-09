class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < cost.size(); i++) {
            a = b;
            b = c;
            c = cost[i] + min(a, b);
        }
        return min(b, c);
    }
};