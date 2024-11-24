class Solution {
    vector<string> getParts(string &s, int partCount) {
        vector<string> parts(partCount);
        for (int i = 0; i < s.size(); i++)
            parts[i / (s.size() / partCount)] += s[i];
        sort(parts.begin(), parts.end());
        return parts;
    }

public:
    bool isPossibleToRearrange(string &a, string &b, int partCount) {
        return getParts(a, partCount) == getParts(b, partCount);
    }
};