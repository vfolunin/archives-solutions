class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        
        while (a || b) {
            if (res.size() >= 2 && res.substr(res.size() - 2) == "bb") {
                res += 'a';
                a--;
            } else if (res.size() >= 2 && res.substr(res.size() - 2) == "aa") {
                res += 'b';
                b--;
            } else if (a >= b) {
                res += 'a';
                a--;
            } else {
                res += 'b';
                b--;
            }
        }
        
        return res;
    }
};