#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, m;
    if (!(cin >> h >> m))
        return 0;

    cout << setw(2) << setfill('0') << h * 12 / 360 << ":";
    cout << setw(2) << setfill('0') << m * 60 / 360 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}