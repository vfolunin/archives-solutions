#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> vars;

    string var, op, a, b;
    while (cin >> var >> op >> a) {
        if (isdigit(a[0])) {
            vars[var] = stoi(a);
        } else {
            cin >> op >> b;
            vars[var] = vars[a] + vars[b];
        }
    }

    cout << vars[var] << "\n";
}