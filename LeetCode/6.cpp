class Solution {
public:
    string convert(string &s, int h) {
        if (h == 1)
            return s;
        
        vector<string> rows(h);
        
        for (int i = 0, y = 0, dy = 1; i < s.size(); i++) {
            rows[y] += s[i];
            if (y == 0 && dy == -1 || y == h - 1 && dy == 1)
                dy *= -1;
            y += dy;
        }
        
        string res;
        for (string &row : rows)
            res += row;
        return res;
    }
};