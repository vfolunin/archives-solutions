class Solution {
public:
    string findReplaceString(string &s, vector<int> &from, vector<string> &a, vector<string> &b) {
        unordered_map<int, int> replaces;
        for (int i = 0; i < from.size(); i++)
            if (s.substr(from[i], a[i].size()) == a[i])
                replaces[from[i]] = i;
        
        string res;
        for (int i = 0; i < s.size(); ) {
            if (replaces.count(i)) {
                res += b[replaces[i]];
                i += a[replaces[i]].size();
            } else {
                res += s[i];
                i++;
            }
        }
        return res;        
    }
};