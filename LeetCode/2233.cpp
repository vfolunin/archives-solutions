class Solution {
public:
    int maximumProduct(vector<int> &a, int k) {
        priority_queue<int, vector<int>, greater<int>> q(a.begin(), a.end());
        for (int i = 0; i < k; i++) {
            int value = q.top();
            q.pop();
            q.push(value + 1);
        }
        
        const long long MOD = 1e9 + 7;
        long long res = 1;
        while (!q.empty()) {
            res = res * q.top() % MOD;
            q.pop();
        }
        return res;
    }
};