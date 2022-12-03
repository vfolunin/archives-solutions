vector<string> split(string &line, const string &separators) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (separators.find(c) == -1) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);
    return words;
}

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    long long r = binPow(x, p / 2);
    return r * r;
}

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
    
    bool operator == (const Fraction &that) const {
        return num == that.num && den == that.den;
    }

    Fraction operator + (const Fraction &that) const {
        return Fraction(num * that.den + that.num * den, den * that.den);
    }
    
    static Fraction parseDecimal(string s) {
        vector<string> parts = split(s, ".()");
        parts.resize(3);
        
        Fraction res(0, 1);
        if (!parts[0].empty())
            res = res + Fraction(stoi(parts[0]), 1);
        if (!parts[1].empty())
            res = res + Fraction(stoi(parts[1]), binPow(10, parts[1].size()));
        if (!parts[2].empty())
            res = res + Fraction(stoi(parts[2]), binPow(10, parts[1].size()) * (binPow(10, parts[2].size()) - 1));                 
        return res;
    }
};

class Solution {
public:
    bool isRationalEqual(string &a, string &b) {
        return Fraction::parseDecimal(a) == Fraction::parseDecimal(b);
    }
};