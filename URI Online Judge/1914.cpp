#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string aName, aChoice, bName, bChoice;
    int a, b;
    cin >> aName >> aChoice >> bName >> bChoice >> a >> b;

    if (((a + b) % 2) ^ (aChoice == "PAR"))
        cout << aName << "\n";
    else
        cout << bName << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}