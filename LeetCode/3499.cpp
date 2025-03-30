class Solution {
public:
    int maxActiveSectionsAfterTrade(string &s) {
        vector<int> groups;

        if (s.front() == '0')
            groups.push_back(1);
        
        groups.push_back(1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                groups.back()++;
            else
                groups.push_back(1);
        }

        if (s.back() == '0')
            groups.push_back(1);

        int res = count(s.begin(), s.end(), '1');
        if (groups.size() < 5)
            return res;
        
        int add = 0;
        for (int i = 1; i + 2 < groups.size(); i += 2)
            add = max(add, groups[i] + groups[i + 2]);
        res += add;
        return res;
    }
};