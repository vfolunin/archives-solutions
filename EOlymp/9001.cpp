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

    int l, r;
    cin >> l >> r;

    if (l <= 0 && 0 <= r)
        cout << 0;
    else if (l < 0 && (r - l + 1) % 2)
        cout << -1;
    else
        cout << 1;
}