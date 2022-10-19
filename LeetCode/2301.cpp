class Solution {
    bool check(string &a, string &b, int from, vector<vector<int>> &can) {
        for (int i = 0; i < b.size(); i++)
            if (a[from + i] != b[i] && !can[a[from + i]][b[i]])
                return 0;
        return 1;
    }
    
public:
    bool matchReplacement(string &a, string &b, vector<vector<char>> &mappings) {
        vector<vector<int>> can(128, vector<int>(128));
        for (vector<char> &mapping : mappings)
            can[mapping[1]][mapping[0]] = 1;
        
        for (int from = 0; from + b.size() <= a.size(); from++)
            if (check(a, b, from, can))
                return 1;
        return 0;
    }
};