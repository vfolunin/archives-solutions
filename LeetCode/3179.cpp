class Solution {
public:
    int valueAfterKSeconds(int size, int k) {
        vector<int> a(size, 1);
        const int MOD = 1e9 + 7;

        for (int i = 0; i < k; i++)
            for (int j = 1; j < a.size(); j++)
                a[j] = (a[j] + a[j - 1]) % MOD;
        
        return a.back();
    }
};