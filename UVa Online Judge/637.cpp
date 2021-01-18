#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << "Printing order for " << n << " pages:\n";

    if (n == 1) {
        cout << "Sheet 1, front: Blank, 1\n";
        return 1;
    }
    
    for (int i = 1, l = 1, r = n + (4 - n % 4) % 4; l < r; i++, l += 2, r -= 2) {
        cout << "Sheet " << i << ", front: ";
        if (r > n)
            cout << "Blank";
        else
            cout << r;
        cout << ", " << l << "\n";

        cout << "Sheet " << i << ", back : ";
        cout << l + 1 << ", ";
        if (r - 1 > n)
            cout << "Blank\n";
        else
            cout << r - 1 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}