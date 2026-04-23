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

    int a, b;
    cin >> a >> b;

    int diff = abs(a - b);
    int l = diff / 2, r = diff - l;

    cout << l * (l + 1) / 2 + r * (r + 1) / 2;
}