class Solution {
    void rec(string &s, int from, long long prevOp, long long curValue, long long targetValue, string expr, vector<string> &exprs) {
        if (from == s.size()) {
            if (curValue == targetValue)
                exprs.push_back(expr);
            return;
        }
        
        for (int partSize = 1; from + partSize <= s.size(); partSize++) {
            if (s[from] == '0' && partSize > 1)
                break;
            
            string part = s.substr(from, partSize);
            long long partValue = stoll(part);
            
            if (from) {
                rec(s, from + partSize, partValue, curValue + partValue, targetValue, expr + "+" + part, exprs);
                rec(s, from + partSize, -partValue, curValue - partValue, targetValue, expr + "-" + part, exprs);
                rec(s, from + partSize, prevOp * partValue, curValue - prevOp + prevOp * partValue, targetValue, expr + "*" + part, exprs);
            } else {
                rec(s, partSize, partValue, partValue, targetValue, part, exprs);
            }
        }
    }
    
public:
    vector<string> addOperators(string &s, int targetValue) {
        vector<string> exprs;
        rec(s, 0, 0, 0, targetValue, "", exprs);
        return exprs;
    }
};