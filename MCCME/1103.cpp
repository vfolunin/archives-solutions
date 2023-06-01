#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string sub1(string s) {
    s.back()--;
    return s;
}

string div2(const string &s) {
    string res;
    int cur = 0;
    for (char c : s) {
        cur = cur * 10 + c - '0';
        res += to_string(cur / 2);
        cur = cur % 2;
    }
    if (res.size() > 1 && res.front() == '0')
        res = res.substr(1);
    return res;
}

long long modM(const string &s, long long mod) {
    long long res = 0;
    for (char c : s)
        if (isdigit(c))
            res = (res * 10 + c - '0') % mod;
    return s[0] == '-' ? mod - res : res;
}

long long binPow(long long n, const string &p, long long mod) {
    if (p == "0")
        return 1;
    if (p.back() % 2)
        return binPow(n, sub1(p), mod) * n % mod;
    long long r = binPow(n, div2(p), mod);
    return r * r % mod;
}

long long binPow(const string &n, const string &p, long long mod) {
    return binPow(modM(n, mod), p, mod);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b[0] != '-' && d[0] != '-') {
        if (a == "0" && b == "0" || c == "0" && d == "0")
            cout << "incorrect";
        else {
            if (binPow(a, b, 1e9 + 7) == binPow(c, d, 1e9 + 7) &&
                binPow(a, b, 1e9 + 9) == binPow(c, d, 1e9 + 9))
                cout << "correct";
            else
                cout << "incorrect";
        }
    } else if (b[0] != '-' && d[0] == '-') {
        if (c == "0")
            cout << "incorrect";
        else {
            d = d.substr(1);
            if (binPow(a, b, 1e9 + 7) * binPow(c, d, 1e9 + 7) == 1 &&
                binPow(a, b, 1e9 + 9) * binPow(c, d, 1e9 + 9) == 1)
                cout << "correct";
            else
                cout << "incorrect";
        }
    } else if (b[0] == '-' && d[0] != '-') {
        if (a == "0")
            cout << "incorrect";
        else {
            b = b.substr(1);
            if (binPow(a, b, 1e9 + 7) * binPow(c, d, 1e9 + 7) == 1 &&
                binPow(a, b, 1e9 + 9) * binPow(c, d, 1e9 + 9) == 1)
                cout << "correct";
            else
                cout << "incorrect";
        }
    } else {
        if (a == "0" || c == "0")
            cout << "incorrect";
        else {
            b = b.substr(1);
            d = d.substr(1);
            if (binPow(a, b, 1e9 + 7) == binPow(c, d, 1e9 + 7) &&
                binPow(a, b, 1e9 + 9) == binPow(c, d, 1e9 + 9))
                cout << "correct";
            else
                cout << "incorrect";
        }
    }
}