class Solution {
public:
    string pushDominoes(string &s) {
        int last = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                if (last == -1 || s[last] == 'L') {
                    fill(s.begin() + last + 1, s.begin() + i, 'L');
                } else {
                    int width = (i - last + 1) / 2;
                    fill(s.begin() + last + 1, s.begin() + last + width, 'R');
                    fill(s.begin() + i - width + 1, s.begin() + i, 'L');
                }
                last = i;
            } else if (s[i] == 'R') {
                if (last != -1 && s[last] == 'R')
                    fill(s.begin() + last + 1, s.begin() + i, 'R');
                last = i;
            }
        }        
        if (last != -1 && s[last] == 'R')
            fill(s.begin() + last + 1, s.end(), 'R');        
        return s;
    }
};