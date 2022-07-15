struct Complex {
    int re, im;
    
    Complex(int re, int im) : re(re), im(im) {}
    
    Complex(const string &s) {
        stringstream ss(s);
        char c;
        ss >> re >> c >> im;
    }
    
    Complex operator * (const Complex &that) const {
        return { re * that.re - im * that.im, re * that.im + im * that.re };
    }
    
    string toString() const {
        stringstream ss;
        ss << re << "+" << im << "i";
        return ss.str();
    }
};

class Solution {
public:
    string complexNumberMultiply(string &a, string &b) {
        return (Complex(a) * Complex(b)).toString();
    }
};