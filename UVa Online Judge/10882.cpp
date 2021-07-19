#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int ab, bc, ac;
    cin >> ab >> bc >> ac;

    int l = max(0, (ab + bc + ac - 100 + 1) / 2);
    int r = min(ab, min(bc, ac));

    cout << "Case #" << test << ": ";
    if (l <= r)
        cout << "Between " << l << " and " << r << " times.\n";
    else
        cout << "The records are faulty.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}