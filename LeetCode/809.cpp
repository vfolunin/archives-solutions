class Solution {
    vector<pair<char, int>> getGroups(string &s) {
        vector<pair<char, int>> groups;
        
        for (int i = 0; i < s.size(); i++) {
            if (!groups.empty() && s[i - 1] == s[i])
                groups.back().second++;
            else
                groups.push_back({ s[i], 1 });
        }
        
        return groups;
    }
    
    bool isStretchy(const vector<pair<char, int>> &a, const vector<pair<char, int>> &b) {
        if (a.size() != b.size())
            return 0;
        
        for (int i = 0; i < a.size(); i++)
            if (a[i].first != b[i].first || a[i].second > b[i].second ||
                a[i].second != b[i].second && b[i].second < 3)
                return 0;
        
        return 1;
    }
    
public:
    int expressiveWords(string &s, vector<string> &words) {
        vector<pair<char, int>> sGroups = getGroups(s);
        
        int res = 0;
        for (string &word : words)
            res += isStretchy(getGroups(word), sGroups);
        return res;
    }
};