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

    int ta, tb, ka, kb;
    cin >> ta >> tb >> ka >> kb;

    int la = (ka - 1) * (1 + ta) + 1;
    int ra = la + 2 * ta;
    int lb = (kb - 1) * (1 + tb) + 1;
    int rb = lb + 2 * tb;

    int l = max(la, lb), r = min(ra, rb);

    if (l <= r)
        cout << l << " " << r;
    else
        cout << -1;
}