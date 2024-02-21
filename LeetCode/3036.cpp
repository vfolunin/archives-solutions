class Solution {
    vector<int> prefixFunction(const string &s) {
        vector<int> p(s.size());
        for (int i = 1; i < s.size(); i++) {
            int border = p[i - 1];
            while (border > 0 && s[i] != s[border])
                border = p[border - 1];
            p[i] = border + (s[i] == s[border]);
        }
        return p;
    }

public:
    int countMatchingSubarrays(vector<int> &values, vector<int> &pattern) {
        string sValues;
        for (int i = 0; i + 1 < values.size(); i++) {
            if (values[i] < values[i + 1])
                sValues += 'a';
            else if (values[i] == values[i + 1])
                sValues += 'b';
            else
                sValues += 'c';
        }
        
        string sPattern;
        for (int value : pattern) {
            if (value == 1)
                sPattern += 'a';
            else if (value == 0)
                sPattern += 'b';
            else
                sPattern += 'c';
        }

        vector<int> p = prefixFunction(sPattern + "#" + sValues);
        return count(p.begin(), p.end(), sPattern.size());
    }
};