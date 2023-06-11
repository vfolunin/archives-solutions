class Solution {
public:
    long long minCost(vector<int> &cost, int shiftCost) {
        long long res = accumulate(cost.begin(), cost.end(), 0LL);

        for (long long shifts = 1; shifts < cost.size(); shifts++) {
            vector<int> nextCost = cost;
            for (int i = 0; i < cost.size(); i++)
                nextCost[i] = min(cost[i], cost[(i + 1) % cost.size()]);
            cost.swap(nextCost);

            res = min(res, accumulate(cost.begin(), cost.end(), shifts * shiftCost));
        }
        
        return res;
    }
};