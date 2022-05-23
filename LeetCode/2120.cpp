class Solution {
    inline static unordered_map<char, pair<int, int>> d = {
        { 'U', { -1, 0 } }, { 'R', { 0, 1 } }, { 'D', { 1, 0 } }, { 'L', { 0, -1 } }
    };
    
    int instructionCount(int size, int y, int x, string &s, int i) {
        int res = 0;
        for ( ; i < s.size(); i++) {
            auto [dy, dx] = d[s[i]];
            y += dy;
            x += dx;
            if (0 <= y && y < size && 0 <= x && x < size)
                res++;
            else
                break;
        }
        return res;
    }
    
public:
    vector<int> executeInstructions(int size, vector<int> &pos, string s) {
        int y = pos[0], x = pos[1];
        
        vector<int> res(s.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = instructionCount(size, y, x, s, i);
        
        return res;
    }
};