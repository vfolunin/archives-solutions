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

    vector<int> perfect = { 6, 28, 496, 8128, 33550336 };

    int l, r;
    cin >> l >> r;

    int found = 0;
    for (int p : perfect) {
        if (l <= p && p <= r) {
            cout << p << "\n";
            found = 1;
        }
    }

    if (!found)
        cout << "Absent";
}