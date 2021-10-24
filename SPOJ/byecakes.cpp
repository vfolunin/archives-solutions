#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> has(4);
    for (int &x : has)
        cin >> x;

    if (has[0] == -1)
        return 0;

    vector<int> needs(4);
    for (int &x : needs)
        cin >> x;

    int cakeCount = 0;
    for (int i = 0; i < 4; i++)
        cakeCount = max(cakeCount, (has[i] + needs[i] - 1) / needs[i]);

    for (int i = 0; i < 4; i++)
        cout << cakeCount * needs[i] - has[i] << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}