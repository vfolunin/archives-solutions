class Solution {
    string countAndSay(string &s) {
        vector<pair<char, int>> groups;
        for (char c : s) {
            if (groups.empty() || groups.back().first != c)
                groups.push_back({ c, 1 });
            else
                groups.back().second++;
        }
        
        stringstream ss;
        for (auto &[c, count] : groups)
            ss << count << c;
        return ss.str();
    }
    
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++)
            res = countAndSay(res);
        return res;
    }
};