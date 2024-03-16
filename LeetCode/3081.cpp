class Solution {
public:
    string minimizeStringValue(string &s) {
        vector<int> count(26);
        for (char c : s)
            if (c != '?')
                count[c - 'a']++;

        set<pair<int, char>> counts;
        for (int i = 0; i < count.size(); i++)
            counts.insert({ count[i], i + 'a' });
        
        string replacements;
        for (char &c : s) {
            if (c == '?') {
                replacements += counts.begin()->second;
                counts.insert({ counts.begin()->first + 1, counts.begin()->second });
                counts.erase(counts.begin());
            }
        }

        sort(replacements.begin(), replacements.end());

        int ri = 0;
        for (char &c : s) {
            if (c == '?') {
                c = replacements[ri];
                ri++;
            }
        }

        return s;
    }
};