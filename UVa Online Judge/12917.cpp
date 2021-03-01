#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int p, h, o;
    if (!(cin >> p >> h >> o))
        return 0;

    cout << (p + h <= o ? "Props" : "Hunters") << " win!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}