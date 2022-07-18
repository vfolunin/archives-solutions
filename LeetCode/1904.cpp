class Solution {
    int getTime(string &s) {
        stringstream ss(s);
        int h, m;
        char colon;
        ss >> h >> colon >> m;
        return h * 60 + m;
    }
    
public:
    int numberOfRounds(string &l, string &r) {
        int tl = getTime(l), tr = getTime(r), res = 0;
        while (tl != tr) {
            res += tl % 15 == 0;
            tl = (tl + 1) % (24 * 60);
        }
        res -= res && (tl % 15 || tr % 15);
        return res;
    }
};