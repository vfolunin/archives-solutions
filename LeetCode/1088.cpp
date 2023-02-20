class Solution {
    bool isValid(long long value) {
        long long rValue = 0;
        for (long long v = value; v; v /= 10) {
            if (v % 10 == 6)
                rValue = rValue * 10 + 9;
            else if (v % 10 == 9)
                rValue = rValue * 10 + 6;
            else
                rValue = rValue * 10 + v % 10;
        }
        return value != rValue;
    }

    int rec(long long value, long long limit) {
        if (value > limit)
            return 0;
        
        int res = isValid(value);
        for (int digit : { 0, 1, 6, 8, 9 })
            res += rec(value * 10 + digit, limit);
        return res;
    }

public:
    int confusingNumberII(long long limit) {
        int res = 0;
        for (int digit : { 1, 6, 8, 9 })
            res += rec(digit, limit);
        return res;
    }
};