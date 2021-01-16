#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

void solve(int test) {
    string s;
    cin >> s;

    map<char, int> letterCount;
    for (char c : s)
        letterCount[c]++;

    long long res = factorial(s.size());
    for (auto &[_, k] : letterCount)
        res /= factorial(k);

    cout << "Data set " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}