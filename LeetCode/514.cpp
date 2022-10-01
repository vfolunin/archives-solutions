class Solution {
    int rec(int i, int lastPos, int size, string &b, vector<vector<int>> &pos, vector<vector<int>> &memo) {
        int &res = memo[i][lastPos];
        if (res)
            return res;
        
        if (!i)
            return res = min(lastPos, size - lastPos) + 1;
        
        res = 1e9;
        for (int prevPos : pos[b[i - 1] - 'a']) {
            int dist = abs(prevPos - lastPos);
            dist = min(dist, size - dist);
            res = min(res, rec(i - 1, prevPos, size, b, pos, memo) + dist + 1);
        }
        return res;
    }
    
public:
    int findRotateSteps(string &a, string &b) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < a.size(); i++)
            pos[a[i] - 'a'].push_back(i);
        
        vector<vector<int>> memo(b.size(), vector<int>(a.size()));
        int res = 1e9;
        
        for (int lastPos : pos[b.back() - 'a'])
            res = min(res, rec(b.size() - 1, lastPos, a.size(), b, pos, memo));
        
        return res;
    }
};