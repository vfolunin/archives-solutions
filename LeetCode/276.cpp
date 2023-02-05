class Solution {
public:
    int numWays(int n, int k) {
        vector<long long> ways(max(3, n + 1));
        
        ways[1] = k;
        ways[2] = k * k;

        for (int i = 3; i <= n; i++)
            ways[i] = (ways[i - 1] + ways[i - 2]) * (k - 1);

        return ways[n];
    }
};