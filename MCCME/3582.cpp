#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(long long n, vector<long long> &fib, int i, string &s) {
    if (i < 0) {
        if (!n)
            cout << s.substr(s.find('1')) << "\n";
        return;
    }

    if (n >= 3 * fib[i])
        return;

    s.push_back('0');
    rec(n, fib, i - 1, s);
    s.pop_back();

    if (n >= fib[i]) {
        s.push_back('1');
        rec(n - fib[i], fib, i - 1, s);
        s.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    vector<long long> fib = { 1, 2 };
    for (int i = 2; fib.back() <= n; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    string s;
    rec(n, fib, fib.size() - 1, s);
}