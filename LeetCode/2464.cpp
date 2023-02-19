class Solution {
public:
    int validSubarraySplit(vector<int> &a) {
        vector<int> cost(a.size() + 1, 1e9);
        cost[0] = 0;

        for (int i = 1; i <= a.size(); i++)
            for (int j = 1; j <= i; j++)
                if (gcd(a[i - 1], a[j - 1]) > 1)
                    cost[i] = min(cost[i], cost[j - 1] + 1);

        return cost.back() < 1e9 ? cost.back() : -1;
    }
};