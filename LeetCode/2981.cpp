class Solution {
public:
    int maximumLength(string &s) {
        for (int res = s.size() - 2; res; res--) {
            for (int i = 0; i + res <= s.size(); i++) {
                string pattern = s.substr(i, res);
                if (set<char>(pattern.begin(), pattern.end()).size() > 1)
                    continue;
                
                int count = 1;
                for (int j = i + 1; j + res <= s.size(); j++)
                    count += s.substr(j, res) == pattern;
                
                if (count >= 3)
                    return res;
            }
        }
        return -1;
    }
};