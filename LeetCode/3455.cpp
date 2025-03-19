vector<string> split(string &s) {
    vector<string> parts;
    string part;
    for (char c : s) {
        if (c != '*') {
            part += c;
        } else {
            parts.push_back(part);
            part.clear();
        }
    }
    parts.push_back(part);
    return parts;
}

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

vector<int> kmp(string &text, string &pattern) {
    vector<int> res;
    if (pattern.empty()) {
        for (int i = 0; i <= text.size(); i++)
            res.push_back(i);
    } else {
        vector<int> p = prefixFunction(pattern + " " + text);
        for (int i = 0; i < p.size(); i++)
            if (p[i] == pattern.size())
                res.push_back(i - 2 * pattern.size());
    }
    return res;
}

class Solution {
public:
    int shortestMatchingSubstring(string &text, string &pattern) {
        vector<string> parts = split(pattern);

        vector<vector<int>> partPos;
        for (string &part : parts)
            partPos.push_back(kmp(text, part));
        
        vector<int> partPosIndex(3);
        int res = 2e9;

        for (partPosIndex[0] = 0; partPosIndex[0] < partPos[0].size(); partPosIndex[0]++) {
            while (partPosIndex[1] < partPos[1].size() && partPos[1][partPosIndex[1]] < partPos[0][partPosIndex[0]] + parts[0].size())
                partPosIndex[1]++;
            while (partPosIndex[1] < partPos[1].size() && partPosIndex[2] < partPos[2].size() && partPos[2][partPosIndex[2]] < partPos[1][partPosIndex[1]] + parts[1].size())
                partPosIndex[2]++;
            if (partPosIndex[1] < partPos[1].size() && partPosIndex[2] < partPos[2].size())
                res = min<int>(res, partPos[2][partPosIndex[2]] + parts[2].size() - partPos[0][partPosIndex[0]]);
        }

        return res != 2e9 ? res : -1;
    }
};