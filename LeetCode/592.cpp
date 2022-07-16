struct Fraction {
    long long num, den;

    void normalize() {
        long long d = gcd(num, den);
        num /= d;
        den /= d;
    }

    Fraction(long long num, long long den) : num(num), den(den) {
        normalize();
    }

    Fraction operator + (const Fraction &that) const {
        return Fraction(num * that.den + that.num * den, den * that.den);
    }

    Fraction operator - (const Fraction &that) const {
        return Fraction(num * that.den - that.num * den, den * that.den);
    }
    
    string toString() {
        stringstream ss;
        ss << num << "/" << den;
        return ss.str();
    }
};

istream &operator >> (istream &in, Fraction &f) {
    char slash;
    in >> f.num >> slash >> f.den;
    f.normalize();
    return in;
}

class Solution {
public:
    string fractionAddition(string &s) {
        stringstream ss(s);
        Fraction res(0, 1), f(0, 1);
        while (ss >> f)
            res = res + f;
        return res.toString();
    }
};