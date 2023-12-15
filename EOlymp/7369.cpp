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

    while (l % 7 != 3)
        l++;
    while (r % 7 != 3)
        r--;

    cout << (r - l) / 7 + 1;
}