struct Hasher {
    long long x = 31, mod = 1e9 + 7;
    vector<long long> p, h;

    Hasher(const string &s) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0] - 'a' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + s[i] - 'a' + 1) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

class Solution {
    bool isPalindrome(Hasher &h, Hasher &hr, int l, int r) {
        return h.getHash(l, r) == hr.getHash(h.p.size() - 1 - r, h.p.size() - 1 - l);
    }
    
public:
    int maxPalindromes(string &s, int k) {
        Hasher h(s);
        reverse(s.begin(), s.end());
        Hasher hr(s);
        
        vector<int> res(s.size());
        for (int r = k - 1; r < s.size(); r++) {
            res[r] = r ? res[r - 1] : 0;
            for (int l = r - k + 1; l >= 0; l--)
                if (isPalindrome(h, hr, l, r))
                    res[r] = max(res[r], 1 + (l ? res[l - 1] : 0));
        }
        return res.back();
    }
};