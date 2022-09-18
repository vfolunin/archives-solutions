#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int countTo(int r) {
    return r / 10 + (r % 10 >= 5);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    l = max(countTo(l) - countTo(1604), 0);
    r = max(countTo(r) - countTo(1604), 0);

    cout << r - l;
}