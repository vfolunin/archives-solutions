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

    long long y, x, h, w;
    cin >> y >> x >> h >> w;

    cout << (y - 1) * (x - 1) - (h + 1) * (w + 1);
}