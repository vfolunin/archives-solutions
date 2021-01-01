#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    string s;
    while (n) {
        s += '0' + n % 2;
        n /= 2;
    }
    reverse(s.begin(), s.end());

    cout << "The parity of " << s << " is ";
    cout << count(s.begin(), s.end(), '1') << " (mod 2).\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}