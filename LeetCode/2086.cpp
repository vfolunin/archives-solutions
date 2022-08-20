class Solution {
public:
    int minimumBuckets(string &s) {
        if (s.size() == 1)
            return s[0] == 'H' ? -1 : 0;
        
        if (s.substr(0, 2) == "HH" || s.substr(s.size() - 2) == "HH")
            return -1;
        
        if (s.size() == 2)
            return s == ".." ? 0 : 1;
        
        if (s.find("HHH") != -1)
            return -1;
        
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'H') {
                if (i && s[i - 1] == 'B')
                    continue;
                
                if (i + 1 < s.size() && s[i + 1] == '.') {
                    s[i + 1] = 'B';
                    res++;
                } else {
                    s[i - 1] = 'B';
                    res++;
                }
            }
        }
        
        return res;
    }
};