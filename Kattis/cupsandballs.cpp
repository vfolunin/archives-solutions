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

    int guess, swapCount;
    cin >> guess >> swapCount;

    vector<int> a = { 0, 1, 0 };
    for (int i = 0; i < swapCount; i++) {
        int lhs, rhs;
        cin >> lhs >> rhs;

        swap(a[lhs - 1], a[rhs - 1]);
    }

    for (int lhs = 0; lhs < a.size(); lhs++) {
        for (int rhs = lhs + 1; rhs < a.size(); rhs++) {
            swap(a[lhs], a[rhs]);
            if (a[guess - 1]) {
                cout << lhs + 1 << " " << rhs + 1;
                return 0;
            }
            swap(a[lhs], a[rhs]);
        }
    }
}