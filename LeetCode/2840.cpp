class Solution {
    vector<string> makeParts(string &s) {
        vector<string> parts(2);
        for (int i = 0; i < s.size(); i++)
            parts[i % 2] += s[i];

        sort(parts[0].begin(), parts[0].end());
        sort(parts[1].begin(), parts[1].end());

        return parts;
    }

public:
    bool checkStrings(string &a, string &b) {
        vector<string> aParts = makeParts(a);
        vector<string> bParts = makeParts(b);
        
        return aParts[0] == bParts[0] && aParts[1] == bParts[1];
    }
};