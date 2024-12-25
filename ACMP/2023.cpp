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

    int d, r, n;
    cin >> d >> r >> n;

    cout << 2 * (r + d) + (n - 1) * 2 * r;
}