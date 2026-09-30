struct Hasher {
    long long mod;
    vector<long long> p, h;

    Hasher(const string &s, long long factor = 31, long long mod = 1e9 + 7) : mod(mod) {
        p.push_back(1);
        for (int i = 1; i < s.size(); i++)
            p.push_back(p[i - 1] * factor % mod);

        h.push_back(s[0] - 'a' + 1);
        for (int i = 1; i < s.size(); i++)
            h.push_back((h[i - 1] * factor % mod + s[i] - 'a' + 1) % mod);
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

struct Candidate {
    int prefixSize;
    bool reverseSuffix;
};

struct Solver {
    string s1, s2;
    Hasher h1, h2;

    Solver(string &s) : s1(s), s2(s.rbegin(), s.rend()), h1(s1), h2(s2) {}

    long long getHash(Candidate &candidate, int size) {
        if (!size)
            return 0;

        if (size <= candidate.prefixSize) {
            if (candidate.reverseSuffix)
                return h1.getHash(0, size - 1);
            else
                return h2.getHash(s1.size() - candidate.prefixSize, s1.size() - candidate.prefixSize + size - 1);
        }

        int suffixSize = size - candidate.prefixSize;

        long long suffixHash = candidate.reverseSuffix ? h2.getHash(0, suffixSize - 1) : h1.getHash(candidate.prefixSize, candidate.prefixSize + suffixSize - 1);
        if (!candidate.prefixSize)
            return suffixHash;

        long long prefixHash = candidate.reverseSuffix ? h1.getHash(0, candidate.prefixSize - 1) : h2.getHash(s1.size() - candidate.prefixSize, s1.size() - 1);
        return (prefixHash * h1.p[suffixSize] + suffixHash) % h1.mod;
    }

    char getChar(Candidate &candidate, int index) {
        if (candidate.reverseSuffix)
            return index < candidate.prefixSize ? s1[index] : s2[index - candidate.prefixSize];
        else
            return index < candidate.prefixSize ? s2[s1.size() - candidate.prefixSize + index] : s1[index];
    }

    bool less(Candidate &lhs, Candidate &rhs) {
        int l = 0, r = s1.size();
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (getHash(lhs, m) == getHash(rhs, m))
                l = m;
            else
                r = m;
        }
        return getChar(lhs, l) < getChar(rhs, l);
    }

    string getString(Candidate &candidate) {
        string res;
        for (int i = 0; i < s1.size(); i++)
            res += getChar(candidate, i);
        return res;
    }

    string getSmallest() {
        Candidate res = { 0, 0 };

        for (int prefixSize = 0; prefixSize <= s1.size(); prefixSize++) {
            for (bool reverseSuffix : { 0, 1 }) {
                Candidate cur = { prefixSize, reverseSuffix };
                if (less(cur, res))
                    res = cur;
            }
        }

        return getString(res);
    }
};

class Solution {
public:
    string lexSmallest(string &s) {
        return Solver(s).getSmallest();
    }
};