class Solution {
public:
    long long countPairs(vector<int> &a, int p) {
        unordered_map<long long, long long> count;
        for (int value : a)
            count[gcd(value, p)]++;
        
        long long res = 0;
        
        for (auto &[a, countA] : count) {
            for (auto &[b, countB] : count)
                if (a < b && a * b % p == 0)
                    res += countA * countB;
            
            if (a * a % p == 0)
                res += countA * (countA - 1) / 2;            
        }
        
        return res;
    }
};