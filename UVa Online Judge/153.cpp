#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class BigInteger {
    static const int BASE = 1e9;
    static const int BASE_LEN = 9;
    static const int MAX_SIZE = 10;
    int d[MAX_SIZE];
    int size;

public:
    BigInteger(long long val = 0) {
        for (int i = 0; i < MAX_SIZE; i++)
            d[i] = 0;
        size = 0;
        if (val == 0)
            d[size++] = 0;
        while (val > 0) {
            d[size++] = val % BASE;
            val /= BASE;
        }
    }

    int cmp(const BigInteger &that) const {
        if (size != that.size)
            return size < that.size ? -1 : 1;
        for (int i = size - 1; i >= 0; i--) {
            if (d[i] != that.d[i])
                return d[i] < that.d[i] ? -1 : 1;
        }
        return 0;
    }

    BigInteger operator + (const BigInteger &that) const {
        BigInteger res;
        int carry = 0;
        for (int i = 0; i < max(size, that.size) || carry != 0; i++) {
            long long x = 0LL + d[i] + that.d[i] + carry;
            res.d[i] = x % BASE;
            carry = x / BASE;
        }
        res.size = max(size, that.size) + 1;
        while (res.size > 1 && res.d[res.size - 1] == 0)
            res.size--;
        return res;
    }

    BigInteger operator - (const BigInteger &that) const {
        BigInteger res;
        int carry = 0;
        for (int i = 0; i < size || carry != 0; i++) {
            long long x = 0LL + d[i] - that.d[i] + carry;
            res.d[i] = (x + BASE) % BASE;
            carry = x < 0 ? -1 : 0;
        }
        res.size = size;
        while (res.size > 1 && res.d[res.size - 1] == 0)
            res.size--;
        return res;
    }

    BigInteger operator * (int that) const {
        BigInteger res;
        int carry = 0;
        for (int i = 0; i < size || carry != 0; i++) {
            long long x = 1LL * d[i] * that + carry;
            res.d[i] = x % BASE;
            carry = x / BASE;
        }
        res.size = size + 1;
        while (res.size > 1 && res.d[res.size - 1] == 0)
            res.size--;
        return res;
    }

    BigInteger operator / (const BigInteger &that) const {
        BigInteger res, carry;
        for (int i = size - 1; i >= 0; i--) {
            carry = carry * BASE;
            carry.d[0] = d[i];
            int l = 0, r = BASE - 1, m;
            while (l + 1 < r) {
                m = l + (r - l) / 2;
                if ((that * m).cmp(carry) <= 0)
                    l = m;
                else
                    r = m;
            }
            res.d[i] = (that * r).cmp(carry) <= 0 ? r : l;
            carry = carry - that * res.d[i];
        }
        res.size = size;
        while (res.size > 1 && res.d[res.size - 1] == 0)
            res.size--;
        return res;
    }

    string toString() const {
        static char spec[] = "%00d";
        spec[2] = BASE_LEN + '0';
        string res = to_string(d[size - 1]);
        char buf[10];
        for (int i = size - 2; i >= 0; i--) {
            sprintf(buf, spec, d[i]);
            res += buf;
        }
        return res;
    }
};

BigInteger fact(int n) {
    BigInteger res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

BigInteger permutationCount(map<char, int> &count) {
    int len = 0;
    for (auto &[_, k] : count)
        len += k;
    BigInteger res = fact(len);
    for (auto &[_, k] : count)
        res = res / fact(k);
    return res;
}

BigInteger number(string s) {
    map<char, int> count;
    for (char c : s)
        count[c]++;

    BigInteger res = 1;
    for (int pos = 0; pos < s.size(); pos++) {
        for (auto &[c, k] : count) {
            if (c < s[pos]) {
                k--;
                res = res + permutationCount(count);
                k++;
            } else {
                break;
            }
        }
        if (!--count[s[pos]])
            count.erase(s[pos]);
    }
    return res;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "#")
        return 0;

    cout << setw(10) << number(s).toString() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}