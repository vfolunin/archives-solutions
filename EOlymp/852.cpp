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

    BigInteger operator / (int that) const {
        BigInteger res;
        res.digits.resize(digits.size());

        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            long long product = 1LL * carry * BASE + digits[i];
            res.digits[i] = product / that;
            carry = product % that;
        }

        while (res.digits.size() > 1 && !res.digits.back())
            res.digits.pop_back();

        return res;
    }

    int operator % (int that) const {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
            carry = (1LL * carry * BASE + digits[i]) % that;
        return carry;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BigInteger a;
    int b;
    cin >> a >> b;

    cout << a / b << "\n" << a % b;
}