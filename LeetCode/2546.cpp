class Solution {
public:
    bool makeStringsEqual(string &a, string &b) {
        unordered_map<string, bool> has;
        for (int i = 0; i < a.size(); i++) 
            has[string(1, a[i]) + string(1, b[i])] = 1;        
        return has["11"] || has["01"] == has["10"];
    }
};