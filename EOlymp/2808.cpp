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

    int index = 0;
    for (int bit = 0; index + (1 << bit) < (r - l + 1); bit += 2)
        index += 1 << bit;

    cout << l + index;
}