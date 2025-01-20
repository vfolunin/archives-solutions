class Solution {
public:
    long long minCost(vector<int> &a, vector<int> &b, long long price) {
        long long cost1 = 0;
        for (int i = 0; i < a.size(); i++)
            cost1 += abs(a[i] - b[i]);
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long cost2 = price;
        for (int i = 0; i < a.size(); i++)
            cost2 += abs(a[i] - b[i]);

        return min(cost1, cost2);
    }
};