#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (!r1)
        return 0;

    if (r1 == r2 && c1 == c2)
        cout << "0\n";
    else if (r1 == r2 || c1 == c2 || r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2)
        cout << "1\n";
    else
        cout << "2\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}