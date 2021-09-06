#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    string line;
    getline(cin, line);

    int res = 0;

    static string digits = " |n98r";
    static vector<int> vals = { 0, 1, 10, 100, 1000, 10000 };
    for (char c : line)
        res += vals[digits.find(c)];

    return res;
}

void write(int n, bool star, bool fill) {
    string res;

    static string digits = "|n98r";
    for (char d : digits) {
        if (n % 10)
            res += (res.empty() ? "" : " ") + string(n % 10, d);
        n /= 10;
    }

    if (star)
        res += " *";

    if (fill)
        res += string(34 - res.size(), ' ');

    cout << res;
}

bool solve() {
    long long a = read(), b = read();
    if (!a && !b)
        return 0;

    long long mod = 1e5, res = a * b % mod;

    for (int p = 1; p <= b; p *= 2, a = (a * 2) % mod) {
        write(p, b & p, 1);
        write(a, 0, 0);
        cout << " \n";
    }

    cout << "The solution is: ";
    write(res, 0, 0);
    cout << " \n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}