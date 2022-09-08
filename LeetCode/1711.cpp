class Solution {
public:
    int countPairs(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        long long res = 0;
        for (auto [valueA, countA] : count) {
            for (int power = 1; power <= 1e7; power *= 2) {
                int valueB = power - valueA;
                if (count.count(valueB)) {
                    int countB = count[valueB];
                    if (valueA == valueB)
                        res += 1LL * countA * (countA - 1);
                    else
                        res += 1LL * countA * countB;
                }
            }
        }
        
        const long long MOD = 1e9 + 7;
        return res / 2 % MOD;
    }
};