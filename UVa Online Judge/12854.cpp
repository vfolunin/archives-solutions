#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> a(5);
    for (int &x : a)
        if (!(cin >> x))
            return 0;

    vector<int> b(5);
    for (int &x : b)
        cin >> x;

    bool compatible = 1;
    for (int i = 0; i < 5; i++)
        compatible &= a[i] ^ b[i];

    cout << (compatible ? "Y\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}