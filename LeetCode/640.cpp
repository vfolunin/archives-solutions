class Solution {
    void read(string &s, int &xCoeff, int xCoeffSign, int &freeCoeff, int freeCoeffSign) {
        stringstream ss(s);
        
        while (ss.peek() != -1) {
            int sign = 1;
            if (ss.peek() == '+' || ss.peek() == '-') {
                if (ss.peek() == '-')
                    sign = -1;
                ss.get();
            }
            
            int n = 1;
            if (ss.peek() != 'x')
                ss >> n;
            
            if (ss && ss.peek() == 'x') {
                ss.get();
                xCoeff += xCoeffSign * sign * n;
            } else {
                freeCoeff += freeCoeffSign * sign * n;
            }
        }
    }
    
public:
    string solveEquation(string &s) {
        int eqPos = s.find('=');
        string l = s.substr(0, eqPos);
        string r = s.substr(eqPos + 1);
        
        int xCoeff = 0, freeCoeff = 0;
        read(l, xCoeff, 1, freeCoeff, -1);
        read(r, xCoeff, -1, freeCoeff, 1);
        
        if (xCoeff)
            return "x=" + to_string(freeCoeff / xCoeff);
        else if (freeCoeff)
            return "No solution";
        else
            return "Infinite solutions";
    }
};