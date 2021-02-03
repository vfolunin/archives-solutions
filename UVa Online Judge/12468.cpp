#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b;
    cin >> a >> b;

    if (a == -1 && b == -1)
        return 0;

    int ab = abs(a - b);
    cout << min(ab, 100 - ab) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}