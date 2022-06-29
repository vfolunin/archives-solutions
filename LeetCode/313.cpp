class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        set<long long> q = { 1 };
        
        for (n--; n; n--) {
            long long value = *q.begin();
            q.erase(q.begin());
            
            for (int prime : primes) {
                q.insert(value * prime);
                while (q.size() > n)
                    q.erase(--q.end());
            }
        }
        
        return *q.begin();
    }
};