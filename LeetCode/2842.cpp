class Solution {
    const long long MOD = 1e9 + 7;

    long long c(int n, int k) {
        static vector<vector<long long>> memo(1000, vector<long long>(1000, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
    }

public:
    int countKSubsequencesWithMaxBeauty(string &s, int size) {
        if (size > 26)
            return 0;
        
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        sort(count.rbegin(), count.rend());
        
        int l = size - 1, r = size - 1;
        while (l >= 0 && count[l] == count[size - 1])
            l--;
        while (r < count.size() && count[size - 1] == count[r])
            r++;
        
        long long res = 1;
        for (int i = 0; i <= l; i++)
            res = res * count[i] % MOD;
        
        int n = r - l - 1, k = size - l - 1;
        res = res * c(n, k) % MOD;
        for (int i = 0; i < k; i++)
            res = res * count[size - 1] % MOD;
        
        return res;
    }
};