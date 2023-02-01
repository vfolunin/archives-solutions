long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    long long r = binPow(x, p / 2);
    return r * r;
}

class Solution {
public:
    bool isArmstrong(int value) {
        string digits = to_string(value);
        long long sum = 0;
        for (char d : digits)
            sum += binPow(d - '0', digits.size());
        return sum == value;
    }
};