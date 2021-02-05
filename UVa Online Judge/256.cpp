#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static map<int, string> ans = {
        {2, "00\n01\n81"},
        {4, "0000\n0001\n2025\n3025\n9801"},
        {6, "000000\n000001\n088209\n494209\n998001"},
        {8, "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001"}
    };

    cout << ans[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}