class Solution {
    unordered_map<string, vector<int>> vars;
    
    int readInt(stringstream &ss) {
        int sign = 1;
        if (ss.peek() == '-') {
            sign = -1;
            ss.get();
        }
        
        int res = 0;
        while (isdigit(ss.peek()))
            res = res * 10 + ss.get() - '0';
        
        return sign * res;
    }
    
    string readVar(stringstream &ss) {
        string res;
        while (isalnum(ss.peek()))
            res += ss.get();
        return res;
    }
    
    int evalLet(stringstream &ss) {
        ss.get();
        
        vector<string> curVars;
        int resReady = 0, res;
        
        while (isalpha(ss.peek())) {
            string var = readVar(ss);
            
            if (ss.peek() == ')') {
                resReady = 1;
                res = vars[var].back();
                break;
            }
            
            ss.get();
            
            curVars.push_back(var);
            vars[var].push_back(evalExpr(ss));
            
            ss.get();
        }
        
        if (!resReady)
            res = evalExpr(ss);
        
        ss.get();
        
        while (!curVars.empty()) {
            vars[curVars.back()].pop_back();
            curVars.pop_back();
        }
        
        return res;
    }
    
    int evalAdd(stringstream &ss) {
        ss.get();
        int a = evalExpr(ss);
        ss.get();
        int b = evalExpr(ss);
        ss.get();
        return a + b;
    }
    
    int evalMult(stringstream &ss) {
        ss.get();
        int a = evalExpr(ss);
        ss.get();
        int b = evalExpr(ss);
        ss.get();
        return a * b;
    }
    
    int evalExpr(stringstream &ss) {
        if (ss.peek() == '-' || isdigit(ss.peek()))
            return readInt(ss);
        
        if (ss.peek() != '(')
            return vars[readVar(ss)].back();

        ss.get();
        string op;
        ss >> op;

        if (op == "let")
            return evalLet(ss);
        else if (op == "add")
            return evalAdd(ss);
        else
            return evalMult(ss);
    }
    
public:
    int evaluate(string &s) {
        stringstream ss(s);
        return evalExpr(ss);
    }
};