class Solution {
public:
    string shortestSuperstring(string &a, string &b) {
        if (a.find(b) != -1)
            return a;
        if (b.find(a) != -1)
            return b;

        for (int border = min(a.size(), b.size()); border; border--) {
            if (a.substr(a.size() - border) == b.substr(0, border))
                return a + b.substr(border);
            if (b.substr(b.size() - border) == a.substr(0, border))
                return b + a.substr(border);
        }
        
        return a + b;
    }
};