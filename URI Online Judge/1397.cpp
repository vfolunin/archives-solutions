#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int resA = 0, resB = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        resA += a > b;
        resB += a < b;
    }

    cout << resA << " " << resB << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}