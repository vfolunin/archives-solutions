#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int cost, paid;
    cin >> cost >> paid;

    if (!cost && !paid)
        return 0;

    static vector<int> bills = { 2, 5, 10, 20, 50, 100 };
    for (int a : bills) {
        for (int b : bills) {
            if (a != b && a + b == paid - cost) {
                cout << "possible\n";
                return 1;
            }
        }
    }

    cout << "impossible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}