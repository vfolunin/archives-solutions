class Solution {
    int getTime(string &s) {
        stringstream ss(s);
        int h, m;
        char colon;
        ss >> h >> colon >> m;
        return h * 60 + m;
    }
    
public:
    int convertTime(string a, string b) {
        int t = getTime(b) - getTime(a);
        if (t < 0)
            t += 24 * 60;
        
        int res = 0;
        for (int delta : { 60, 15, 5, 1 }) {
            res += t / delta;
            t %= delta;
        }
        return res;
    }
};