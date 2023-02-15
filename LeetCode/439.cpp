class Solution {
    string eval(stringstream &ss) {
        char c;
        ss >> c;

        if (isdigit(c) || ss.peek() != '?')
            return string(1, c);

        ss.get();

        if (c == 'T')
            return eval(ss);
        
        int depth = 0;
        while (ss >> c) {
            if (c == '?') {
                depth++;
            } else if (c == ':') {
                if (depth)
                    depth--;
                else
                    return eval(ss);
            }
        }

        return "";
    }

public:
    string parseTernary(string &s) {
        stringstream ss(s);
        return eval(ss);
    }
};