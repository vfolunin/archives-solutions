class Solution {
public:
    int makeArrayIncreasing(vector<int> &a, vector<int> &b) {
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        vector<vector<int>> cost(a.size(), vector<int>(b.size() + 1, 1e9));
        for (int bi = 0; bi < b.size(); bi++)
            cost[0][bi] = 1;
        cost[0][b.size()] = 0;

        for (int ai = 1; ai < a.size(); ai++) {
            int minPrevCost = 1e9;
            for (int bi = 0; bi < b.size(); bi++) {
                cost[ai][bi] = min(cost[ai][bi], minPrevCost + 1);
                minPrevCost = min(minPrevCost, cost[ai - 1][bi]);
                if (a[ai - 1] < b[bi])
                    cost[ai][bi] = min(cost[ai][bi], cost[ai - 1][b.size()] + 1);
            }

            for (int prevBi = 0; prevBi < b.size() && b[prevBi] < a[ai]; prevBi++)
                cost[ai][b.size()] = min(cost[ai][b.size()], cost[ai - 1][prevBi]);
            if (a[ai - 1] < a[ai])
                cost[ai][b.size()] = min(cost[ai][b.size()], cost[ai - 1][b.size()]);
        }

        int res = *min_element(cost.back().begin(), cost.back().end());
        return res != 1e9 ? res : -1;
    }
};