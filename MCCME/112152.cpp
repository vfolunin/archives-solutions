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

    double l, r;
    cin >> l >> r;

    cout.precision(3);
    for (int i = 0; i < 5; i++)
        cout << fixed << l + (r - l) / 5 * i << " ";
}