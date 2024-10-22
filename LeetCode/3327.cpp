struct Hasher {
    long long x, mod;
    vector<long long> p, h;

    Hasher(const string &s, long long x = 31, long long mod = 1e9 + 7) : x(x), mod(mod) {
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

struct PalindromeChecker {
    Hasher hl, hr;

    PalindromeChecker(const string &s) : hl(s), hr({ s.rbegin(), s.rend() }) {}

    bool isPalindrome(int l, int r) {
        return hl.getHash(l, r) == hr.getHash(hr.h.size() - 1 - r, hr.h.size() - 1 - l);
    }
};

class Solution {
    void dfs(vector<vector<int>> &graph, int v, string &letters, string &s, vector<int> &l, vector<int> &r) {
        l[v] = s.size();

        for (int to : graph[v])
            dfs(graph, to, letters, s, l, r);
        
        s.push_back(letters[v]);
        r[v] = s.size() - 1;
    }

public:
    vector<bool> findAnswer(vector<int> &from, string &letters) {
        vector<vector<int>> graph(from.size());
        for (int v = 1; v < graph.size(); v++)
            graph[from[v]].push_back(v);
        
        string s;
        vector<int> l(graph.size()), r(graph.size());
        dfs(graph, 0, letters, s, l, r);

        PalindromeChecker palindromeChecker(s);
        vector<bool> res(graph.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = palindromeChecker.isPalindrome(l[i], r[i]);
        return res;
    }
};