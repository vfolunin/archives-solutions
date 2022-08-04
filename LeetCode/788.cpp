class Solution {
    bool isGood(int n) {
        string a = to_string(n), b = a;
        
        for (char &c : a) {
            if (c == '3' || c == '4' || c == '7')
                return 0;
            if (c == '2' || c == '5')
                c = '2' + '5' - c;
            if (c == '6' || c == '9')
                c = '6' + '9' - c;
        }
        
        return a != b;
    }
    
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += isGood(i);
        return res;
    }
};