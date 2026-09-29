class Solution {
    long long eval(stringstream &ss) {
        if (isalpha(ss.peek())) {
            char type;
            ss >> type;

            for (int i = 0; i < 3; i++)
                ss.ignore();
            
            long long a = eval(ss);
            ss.ignore();
            long long b = eval(ss);
            ss.ignore();

            if (type == 'a')
                return a + b;
            else if (type == 's')
                return a - b;
            else if (type == 'm')
                return a * b;
            else
                return a / b;
        } else {
            string token;
            while (isdigit(ss.peek()) || ss.peek() == '-')
                token += ss.get();

            return stoll(token);
        }
    }

public:
    long long evaluateExpression(string &s) {
        stringstream ss(s);
        return eval(ss);
    }
};