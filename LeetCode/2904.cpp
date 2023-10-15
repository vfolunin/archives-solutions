class Solution {
public:
    string shortestBeautifulSubstring(string &s, int ones) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string cur = s.substr(i, j - i + 1);
                if (count(cur.begin(), cur.end(), '1') == ones &&
                    (res.empty() || res.size() > cur.size() || res.size() == cur.size() && res > cur))
                    res = cur;
            }
        }
        return res;
    }
};