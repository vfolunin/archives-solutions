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

    if (l > r)
        swap(l, r);

    int bit = 30;
    while (bit >= 0 && (l & (1 << bit)) == (r & (1 << bit)))
        bit--;

    cout << (1 << (bit + 1)) - 1;
}