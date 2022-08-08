class Solution {
public:
    string entityParser(string &s) {
        vector<pair<string, string>> symbols = {
            { "&quot;", "\"" }, { "&apos;", "'" }, { "&amp;", "&" },
            { "&gt;", ">" }, { "&lt;", "<" }, { "&frasl;", "/" }
        };
        
        string res;        
        for (int i = 0; i < s.size(); i++) {
            res += s[i];
            for (auto &[a, b] : symbols) {
                if (i + 1 >= a.size() && !s.compare(i + 1 - a.size(), a.size(), a)) {
                    res.erase(res.size() - a.size());
                    res += b;
                }
            }
        }        
        return res;
    }
};