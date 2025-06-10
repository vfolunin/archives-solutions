class Solution {
public:
    int countPermutations(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        long long res = 1;

        for (int i = 1; i < a.size(); i++) {
            if (a[i] <= a[0])
                return 0;
            
            res = res * i % MOD;
        }

        return res;
    }
};