class Solution {
public:
    int minimumTime(vector<int> &a, vector<int> &d, int limit) {
        vector<int> order(a.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return d[lhs] < d[rhs];
        });

        vector<vector<long long>> maxSub(a.size() + 1, vector<long long>(a.size() + 1));
        for (int items = 1; items <= a.size(); items++)
            for (int ops = 1; ops <= items; ops++)
                maxSub[items][ops] = max(
                    maxSub[items - 1][ops],
                    maxSub[items - 1][ops - 1] + a[order[items - 1]] + d[order[items - 1]] * ops
                );
        
        long long aSum = accumulate(a.begin(), a.end(), 0);
        long long dSum = accumulate(d.begin(), d.end(), 0);

        for (int ops = 0; ops <= a.size(); ops++)
            if (aSum + dSum * ops - maxSub[a.size()][ops] <= limit)
                return ops;
        
        return -1;
    }
};