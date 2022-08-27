class Solution {
public:
    string fractionToDecimal(long long num, long long den) {
        if (!num)
            return "0";
        
        if (num < 0 && den < 0) {
            num = abs(num);
            den = abs(den);
        }
        
        string res;
        
        if (num < 0 || den < 0) {
            res += "-";
            num = abs(num);
            den = abs(den);
        }
        
        res += to_string(num / den);
        num %= den;
        if (num)
            res += ".";
        
        unordered_map<int, int> seen;
        vector<int> digits;
        
        for (int i = 0; num; i++) {
            if (seen.count(num)) {
                for (int j = 0; j < seen[num]; j++)
                    res += digits[j] + '0';
                res += "(";
                for (int j = seen[num]; j < i; j++)
                    res += digits[j] + '0';
                res += ")";
                return res;
            }
            
            seen[num] = i;
            
            digits.push_back(num * 10 / den);
            num = num * 10 % den;
        }
        
        for (int d : digits)
            res += d + '0';
        return res;
    }
};