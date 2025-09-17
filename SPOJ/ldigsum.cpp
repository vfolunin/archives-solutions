#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitRoot(int n) {
    if (n < 10)
        return n;

    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return digitRoot(sum);
}

int digitRoot(string &s) {
    int sum = 0;
    for (char c : s)
        sum += c - '0';
    return digitRoot(sum);
}

void solve() {
    string s;
    cin >> s;

    cout << digitRoot(s) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}