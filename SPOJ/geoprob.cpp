#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BigInteger {
    vector<int> digits;
    inline static const int BASE = 1e9;
    inline static const int DIGIT_WIDTH = 9;

    inline int digit(int index) const {
        return index < digits.size() ? digits[index] : 0;
    }

    inline int &digit(int index) {
        if (digits.size() <= index)
            digits.resize(index + 1);
        return digits[index];
    }

    inline void removeZeros() {
        while (!digits.empty() && !digits.back())
            digits.pop_back();
    }

    BigInteger(long long value = 0) {
        for (; value; value /= BASE)
            digits.push_back(value % BASE);
    }

    BigInteger(const string &s) {
        for (int r = s.size() - 1; r >= 0; r -= DIGIT_WIDTH) {
            int l = max(r - DIGIT_WIDTH + 1, 0);
            digits.push_back(stoi(s.substr(l, r - l + 1)));
        }
        removeZeros();
    }

    BigInteger operator + (const BigInteger &that) const {
        BigInteger res;
        for (int i = 0, carry = 0; i < digits.size() || i < that.digits.size() || carry; i++) {
            int cur = digit(i) + that.digit(i) + carry;
            res.digits.push_back(cur % BASE);
            carry = cur / BASE;
        }
        return res;
    }

    BigInteger operator - (const BigInteger &that) const {
        BigInteger res;
        for (int i = 0, carry = 0; i < digits.size() || carry; i++) {
            int cur = digit(i) - that.digit(i) + carry;
            res.digits.push_back((cur + BASE) % BASE);
            carry = cur < 0 ? -1 : 0;
        }
        res.removeZeros();
        return res;
    }

    friend istream &operator >> (istream &in, BigInteger &value) {
        string s;
        in >> s;
        value = BigInteger(s);
        return in;
    }

    friend ostream &operator << (ostream &out, const BigInteger &value) {
        if (value.digits.empty()) {
            out << 0;
        } else {
            out << value.digits.back();
            for (int i = (int)value.digits.size() - 2; i >= 0; i--) {
                out.width(DIGIT_WIDTH);
                out.fill('0');
                out << value.digits[i];
            }
        }
        return out;
    }
};

void solve() {
    BigInteger a, b, c;
    cin >> a >> b >> c;

    cout << b + b - a - c << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}