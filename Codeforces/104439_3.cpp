#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(int d, int l, int r) {
    return r / d - (l - 1) / d;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int d1, d2, l, r;
    cin >> d1 >> d2 >> l >> r;

    cout << getCount(d1, l, r) - getCount(d2, l, r);
}