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

    long long l, r;
    cin >> l >> r;

    if (l > r)
        swap(l, r);
    l++;
    r--;

    cout << (r - l + 1) / 2 + (l % 2 == 0 && r % 2 == 0);
}