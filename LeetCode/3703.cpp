class Solution {
public:
    string removeSubstring(string &s, int limit) {
        vector<pair<char, int>> parts;
        for (char c : s) {
            if (!parts.empty() && parts.back().first == c)
                parts.back().second++;
            else
                parts.push_back({ c, 1 });
            
            if (parts.back().first == ')' && parts.back().second == limit &&
                parts.size() > 1 && parts[parts.size() - 2].second >= limit) {
                parts.pop_back();
                parts.back().second -= limit;
                if (!parts.back().second)
                    parts.pop_back();
            }
        }

        string res;
        for (auto &[c, count] : parts)
            res += string(count, c);
        return res;
    }
};