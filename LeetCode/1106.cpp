class Solution {
    bool parse(stringstream &ss) {
        char c = ss.get();
        
        if (c == '!') {
            ss.get();
            bool res = parse(ss);
            ss.get();
            return !res;
        }
        
        if (c == '&') {
            bool res = 1;
            while (ss.peek() != ')') {
                ss.get();
                res &= parse(ss);
            }
            ss.get();
            return res;
        }
        
        if (c == '|') {
            bool res = 0;
            while (ss.peek() != ')') {
                ss.get();
                res |= parse(ss);
            }
            ss.get();
            return res;
        }
        
        return c == 't';
    }
    
public:
    bool parseBoolExpr(string &s) {
        stringstream ss(s);
        return parse(ss);
    }
};