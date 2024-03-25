#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BigInteger {
    static const int BASE = 1e9;
    static const int SIZE = 9;
    vector<int> digits;

    friend istream &operator >> (istream &in, BigInteger &value) {
        string s;
        in >> s;

        for (int l = max((int)s.size() - SIZE, 0), r = s.size() - 1; r >= 0; l = max(l - SIZE, 0), r -= SIZE)
            value.digits.push_back(stoi(s.substr(l, r - l + 1)));

        return in;
    }

    friend ostream &operator << (ostream &out, const BigInteger &value) {
        out << value.digits.back();
        for (int i = (int)value.digits.size() - 2; i >= 0; i--)
            out << setw(SIZE) << setfill('0') << value.digits[i];

        return out;
    }

    BigInteger operator * (const BigInteger &that) const {
        BigInteger res;
        res.digits.resize(digits.size() + that.digits.size());

        for (int i = 0; i < digits.size(); i++) {
            int carry = 0;
            for (int j = 0; j < that.digits.size() || carry; j++) {
                long long product = res.digits[i + j] + 1LL * digits[i] * that.digits[j] + carry;
                res.digits[i + j] = product % BASE;
                carry = product / BASE;
            }
        }

        while (res.digits.size() > 1 && !res.digits.back())
            res.digits.pop_back();

        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BigInteger a, b;
    cin >> a >> b;

    cout << a * b;
}