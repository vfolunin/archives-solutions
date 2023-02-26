class Solution {
    int getDiff(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
            diff |= (a[i] != b[i]) << i;
        return diff;
    }

    pair<string, int> getAbbr(string &s, int mask) {
        string abbr;
        int abbrSize = 0, from = 0;

        for (int i = 0; i < s.size(); ) {
            if (mask & (1 << i)) {
                abbr += s[i];
                abbrSize++;
                i++;
            } else {
                int j = i;
                while (j < s.size() && !(mask & (1 << j)))
                    j++;
                abbr += to_string(j - i);
                abbrSize++;
                i = j;
            }
        }

        return { abbr, abbrSize };
    }

public:
    string minAbbreviation(string &s, vector<string> &words) {
        unordered_set<int> diffs;
        for (string &word : words)
            if (s.size() == word.size())
                diffs.insert(getDiff(s, word));
        
        string res;
        int resSize = 1e9;

        for (int mask = 0; mask < (1 << s.size()); mask++) {
            bool ok = 1;
            for (int diff : diffs)
                ok &= (mask & diff) > 0;
            if (!ok)
                continue;
            
            auto [abbr, abbrSize] = getAbbr(s, mask);
            if (resSize > abbrSize) {
                res = abbr;
                resSize = abbrSize;
            }
        }
        
        return res;
    }
};