class Solution {
public:
    int miceAndCheese(vector<int> &cost1, vector<int> &cost2, int k) {
        vector<int> order(cost1.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return cost1[a] - cost2[a] > cost1[b] - cost2[b];
        });
        
        int res = 0;
        for (int i = 0; i < k; i++)
            res += cost1[order[i]];
        for (int i = k; i < order.size(); i++)
            res += cost2[order[i]];
        return res;
    }
};