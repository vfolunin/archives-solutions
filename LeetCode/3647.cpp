class Solution {
public:
    int maxWeight(vector<int> &weights, int limit1, int limit2) {
        vector<vector<int>> can(limit1 + 1, vector<int>(limit2 + 1));
        can[0][0] = 1;

        for (int weight : weights)
            for (int sum1 = limit1; sum1 >= 0; sum1--)
                for (int sum2 = limit2; sum2 >= 0; sum2--)
                    can[sum1][sum2] |= sum1 >= weight && can[sum1 - weight][sum2] || sum2 >= weight && can[sum1][sum2 - weight];

        int res = 0;
        for (int sum1 = 0; sum1 <= limit1; sum1++)
            for (int sum2 = 0; sum2 <= limit2; sum2++)
                if (can[sum1][sum2])
                    res = max(res, sum1 + sum2);
        return res;
    }
};