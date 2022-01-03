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

    if (!n)
        return 0;

    n *= n;

    string res;
    while (n > 3) {
        res += 'A' + n % 4;
        n /= 4;
    }
    res += 'A' + n % 4;
    reverse(res.begin(), res.end());

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}