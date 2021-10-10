#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    if (!h1 && !m1 && !h2 && !m2)
        return 0;

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    if (t1 >= t2)
        t2 += 24 * 60;

    cout << t2 - t1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}