class Solution {
    int readValue(stringstream &ss) {
        int sign = 1;
        if (ss.peek() == '+' || ss.peek() == '-') {
            if (ss.peek() == '-')
                sign = -1;
            ss.get();
        }
        
        int value;
        if (ss.peek() == '(')
            value = readBracket(ss);
        else
            ss >> value;
        return sign * value;
    }
    
    int readBracket(stringstream &ss) {
        ss.get();
        int sum = 0;
        while (ss.peek() != ')')
            sum += readValue(ss);
        ss.get();
        return sum;
    }
    
public:
    int calculate(string &s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        stringstream ss(s);
        
        int sum = 0;
        while (ss.peek() != EOF)
            sum += readValue(ss);
        return sum;
    }
};