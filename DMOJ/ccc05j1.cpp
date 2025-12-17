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

    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    int a = max(t1 - 100, 0) * 25 + t2 * 15 + t3 * 20;
    int b = max(t1 - 250, 0) * 45 + t2 * 35 + t3 * 25;

    cout.precision(2);
    cout << "Plan A costs " << fixed << a / 100.0 << "\n";
    cout << "Plan B costs " << fixed << b / 100.0 << "\n";
    if (a != b)
        cout << "Plan " << (a < b ? "A" : "B") << " is cheapest.";
    else
        cout << "Plan A and B are the same price.";
}