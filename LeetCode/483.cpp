class Solution {
    long long getSum(long long base, int power, long long limit) {
        long long sum = 1, summand = 1;
        for (int i = 1; i < power; i++) {
            if (sum > limit / base)
                return limit + 1;
            summand *= base;
            sum += summand;
        }
        return sum;
    }

    long long getBase(int power, long long value) {
        long long l = 2, r = value;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (getSum(m, power, value) <= value)
                l = m;
            else
                r = m;
        }

        return getSum(l, power, value) == value ? l : 0;
    }
    
public:
    string smallestGoodBase(string &s) {
        long long value = stoll(s);
        
        for (int power = 61; power; power--)
            if (long long base = getBase(power, value))
                return to_string(base);
        
        return to_string(value - 1);
    }
};