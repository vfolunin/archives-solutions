#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    cin >> a >> b;

    if (a == "*")
        return 0;

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i] && (!i || a[i - 1] == b[i - 1]);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}