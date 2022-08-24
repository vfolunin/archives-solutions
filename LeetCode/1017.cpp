class Solution {
public:
    string baseNeg2(int n) {
        string res;
        
        while (n) {
            int remainder = n % -2;
            n /= -2;
            
            if (remainder == -1) {
                remainder = 1;
                n++;
            }
            
            res += remainder + '0';
        }
        
        reverse(res.begin(), res.end());
        if (res.empty())
            res += "0";
        
        return res;
    }
};