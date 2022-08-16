class Solution {
public:
    int numSteps(string &s) {
        int res = 0;
        
        while (s.size() > 1) {
            cout << s << "\n";
            if (s.back() == '0') {
                s.pop_back();
                res++;
            } else {
                int pos = s.rfind('0');
                res += s.size() - pos;
                if (pos != -1) {
                    s[pos]++;
                    s.erase(s.begin() + pos + 1, s.end());
                } else {
                    break;
                }
            }
        }
        
        return res;
    }
};