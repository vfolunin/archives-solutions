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

    int x, l, r;
    cin >> x >> l >> r;

    cout << (l <= x && x <= r ? "YES" : "NO");
}