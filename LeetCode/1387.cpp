class Solution {
    int getCollatz(int n) {
        static vector<int> memo((int)1e6, -1);
        int &res = memo[n];
        if (res != -1)
            return res;
        
        if (n == 1)
            return res = 0;
        
        return res = 1 + getCollatz(n % 2 ? 3 * n + 1 : n / 2);
    }
    
public:
    int getKth(int l, int r, int k) {
        vector<int> res(r - l + 1);
        iota(res.begin(), res.end(), l);
        
        nth_element(res.begin(), res.begin() + k - 1, res.end(), [&](int a, int b) {
            int ca = getCollatz(a), cb = getCollatz(b);
            if (ca != cb)
                return ca < cb;
            return a < b;
        });
        
        return res[k - 1];
    }
};