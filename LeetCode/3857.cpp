class Solution {
public:
    int minCost(int n) {
        vector<int> minCost(n + 1, 1e9);
        minCost[1] = 0;
        for (int i = 2; i < minCost.size(); i++)
            for (int a = 1, b = i - 1; a <= b; a++, b--)
                minCost[i] = min(minCost[i], minCost[a] + minCost[b] + a * b);
        return minCost[n];
    }
};