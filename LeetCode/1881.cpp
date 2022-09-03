class Solution {
public:
    string maxValue(string &s, int d) {
        d += '0';
        bool inserted = 0;
        
        if (s[0] == '-') {
            for (int i = 1; i < s.size(); i++) {
                if (d < s[i]) {
                    s.insert(s.begin() + i, d);
                    inserted = 1;
                    break;
                }
            }     
        } else {
            for (int i = 0; i < s.size(); i++) {
                if (d > s[i]) {
                    s.insert(s.begin() + i, d);
                    inserted = 1;
                    break;
                }
            }
        }
        
        if (!inserted)
            s += d;
        
        return s;
    }
};