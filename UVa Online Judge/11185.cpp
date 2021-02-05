#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    cin >> n;

    if (n < 0)
        return 0;

    string s;
    while (n > 2) {
        s += '0' + n % 3;
        n /= 3;
    }
    s += '0' + n;
    reverse(s.begin(), s.end());

    cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}