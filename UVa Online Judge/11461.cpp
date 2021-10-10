#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    int res = 0;
    for (int i = 1; i * i <= r; i++)
        res += l <= i * i;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}