class Solution {
public:
    int minimumRecolors(string &s, int k) {
        int window = count(s.begin(), s.begin() + k, 'W'), res = window;
        
        for (int i = k; i < s.size(); i++) {
            window -= s[i - k] == 'W';
            window += s[i] == 'W';
            res = min(res, window);
        }
        
        return res;
    }
};