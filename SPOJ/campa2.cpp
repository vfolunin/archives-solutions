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

    int res = 0;
    for (int i = h1 * 60 + m1; i < h2 * 60 + m2; i++)
        res += i % 15 == 0;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    while (solve());
}