class Solution {
    int rec(vector<int> &a, vector<int> &b, int taken, int takenL, vector<vector<int>> &memo) {
        if (taken == b.size())
            return 0;
        
        int &res = memo[taken][takenL];
        if (res != -2e9)
            return res;
        
        int takenR = taken - takenL;
        return res = max(a[takenL] * b[taken] + rec(a, b, taken + 1, takenL + 1, memo),
                         a[a.size() - 1 - takenR] * b[taken] + rec(a, b, taken + 1, takenL, memo));
    }
    
public:
    int maximumScore(vector<int> &a, vector<int> &b) {
        vector<vector<int>> memo(b.size(), vector<int>(b.size(), -2e9));
        return rec(a, b, 0, 0, memo);
    }
};