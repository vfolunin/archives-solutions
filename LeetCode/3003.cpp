class Solution {
    int letterCount(vector<vector<int>> &p, int l, int r, int i, int oldLetter, int newLetter) {
        int res = 0;
        for (int letter = 0; letter < p[0].size(); letter++) {
            int count = p[r][letter] - (l ? p[l - 1][letter] : 0);
            if (l <= i && i <= r) {
                count -= letter == oldLetter;
                count += letter == newLetter;
            }
            res += count > 0;
        }
        return res;
    }

    int getTo(vector<vector<int>> &p, int from, int i, int oldLetter, int newLetter, int limit) {
        int l = from, r = p.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (letterCount(p, from, m, i, oldLetter, newLetter) <= limit)
                l = m;
            else
                r = m;
        }
        return l;
    }

    int getPartCount(vector<vector<int>> &p, vector<int> &partL, vector<int> &partR, vector<int> &partFrom,
                     int i, int oldLetter, int newLetter, int limit) {
        if (i) {
            int from = partFrom[i - 1], to = getTo(p, from, i, oldLetter, newLetter, limit);
            if (i <= to)
                return 1 + (to + 1 < partR.size() ? partR[to + 1] : 0);
        }

        int from = i, to = getTo(p, from, i, oldLetter, newLetter, limit);
        return (from ? partL[from - 1] : 0) + 1 + (to + 1 < partR.size() ? partR[to + 1] : 0);
    }

public:
    int maxPartitionsAfterOperations(string &s, int limit) {
        vector<vector<int>> p(s.size(), vector<int>(26));
        p[0][s[0] - 'a'] = 1;
        for (int i = 1; i < s.size(); i++)
            for (int letter = 0; letter < p[0].size(); letter++) 
                p[i][letter] = p[i - 1][letter] + (s[i] == letter + 'a');
        
        unordered_set<char> letters = { s.front() };
        vector<int> partL(s.size(), 1), partFrom(s.size());
        for (int i = 1; i < s.size(); i++) {
            letters.insert(s[i]);
            if (letters.size() <= limit) {
                partL[i] = partL[i - 1];
                partFrom[i] = partFrom[i - 1];
            } else {
                letters = { s[i] };
                partL[i] = partL[i - 1] + 1;
                partFrom[i] = i;
            }
        }

        letters = { s.back() };
        vector<int> partR(s.size(), 1);
        for (int i = (int)s.size() - 2; i >= 0; i--) {
            letters.insert(s[i]);
            if (letters.size() <= limit) {
                partR[i] = partR[i + 1];
            } else {
                letters = { s[i] };
                partR[i] = partR[i + 1] + 1;
            }
        }

        int res = 0;
        for (int i = 0; i < s.size(); i++)
            for (int newLetter = 0; newLetter < p[0].size(); newLetter++)
                res = max(res, getPartCount(p, partL, partR, partFrom, i, s[i] - 'a', newLetter, limit));
        return res;
    }
};