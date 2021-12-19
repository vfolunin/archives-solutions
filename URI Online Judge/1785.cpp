#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int next(int n) {
    string s = to_string(n);
    s = string(4 - s.size(), '0') + s;

    sort(s.begin(), s.end());
    if (s[0] == s[3])
        return -1;
    int a = stoi(s);

    reverse(s.begin(), s.end());
    int b = stoi(s);

    return b - a;
}

int kaprekar(int n) {
    int res = 0;
    while (n != -1 && n != 6174) {
        n = next(n);
        res++;
    }
    return n != -1 ? res : n;
}

void solve(int test) {
    int n;
    cin >> n;

    cout << "Caso #" << test << ": " << kaprekar(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}