class Solution {
    int parseTime(string &s) {
        stringstream ss(s);
        
        int h, m;
        char colon;
        ss >> h >> colon >> m;
        
        return h * 60 + m;
    }
    
public:
    bool haveConflict(vector<string> &a, vector<string> &b) {
        int al = parseTime(a[0]), ar = parseTime(a[1]);
        int bl = parseTime(b[0]), br = parseTime(b[1]);
        return al <= br && bl <= ar;
    }
};