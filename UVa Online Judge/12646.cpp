#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    if (a != b && a != c)
        cout << "A\n";
    else if (b != a && b != c)
        cout << "B\n";
    else if (c != a && c != b)
        cout << "C\n";
    else
        cout << "*\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}