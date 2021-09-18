#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> prepare() {
    set<int> hexNumbers;
    for (int i = 0; 3 * i * (i + 1) + 1 <= 1e9; i++)
        hexNumbers.insert(3 * i * (i + 1) + 1);
    return hexNumbers;
}

bool solve() {
    int n;
    cin >> n;

    if (n == -1)
        return 0;

    static set<int> hexNumbers = prepare();
    
    cout << (hexNumbers.count(n) ? "Y\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}