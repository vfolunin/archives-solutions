struct PalindromeChecker {
    vector<int> p;

    PalindromeChecker(const string &s) {
        p.resize(s.size());
        for (int i = 0; i < p.size(); i++)
            p[i] = (s[i] == s[s.size() - 1 - i]) + (i ? p[i - 1] : 0);
    }

    bool isPalindrome(int l, int r) {
        if (l > r)
            return 1;
        return p[r] - (l ? p[l - 1] : 0) == r - l + 1;
    }
};

using Letters = valarray<int>;

struct LetterCounter {
    vector<Letters> p;

    LetterCounter(const string &s) {
        p.resize(s.size());
        for (int i = 0; i < p.size(); i++) {
            p[i].resize(26);
            p[i][s[i] - 'a']++;
            if (i)
                p[i] += p[i - 1];
        }
    }

    Letters getLetters(int l, int r) {
        Letters res(26);
        if (l > r)
            return res;
        res = p[r];
        if (l)
            res -= p[l - 1];
        return res;
    }
};

bool check(Letters &ab, Letters &cd) {
    for (int i = 0; i < ab.size(); i++)
        if (ab[i] < 0 || ab[i] != cd[i])
            return 0;
    return 1;
}

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string &s, vector<vector<int>> &queries) {
        PalindromeChecker palindromeChecker(s);
        LetterCounter letterCounter(s);
        vector<bool> res(queries.size());

        for (int i = 0; i < res.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            int c = queries[i][2], d = queries[i][3];

            int ar = s.size() - 1 - a, br = s.size() - 1 - b;
            int cr = s.size() - 1 - c, dr = s.size() - 1 - d;

            if (!palindromeChecker.isPalindrome(0, min(a, dr) - 1) ||
                !palindromeChecker.isPalindrome(b + 1, dr - 1) ||
                !palindromeChecker.isPalindrome(cr + 1, a - 1) ||
                !palindromeChecker.isPalindrome(max(b, cr) + 1, s.size() / 2 - 1))
                continue;

            Letters abLetters = letterCounter.getLetters(a, b);
            abLetters -= letterCounter.getLetters(br, min(ar, c - 1));
            abLetters -= letterCounter.getLetters(max(br, d + 1), ar);

            Letters cdLetters = letterCounter.getLetters(c, d);
            cdLetters -= letterCounter.getLetters(dr, min(cr, a - 1));
            cdLetters -= letterCounter.getLetters(max(dr, b + 1), cr);
            
            res[i] = check(abLetters, cdLetters);
        }

        return res;
    }
};