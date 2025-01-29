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

    long long h, w, n;
    cin >> h >> w >> n;

    if (h > w)
        swap(h, w);

    int res = h / 2;
    while (res * 2 * w + (h - 2 * res) * 2 * res > n)
        res--;

    cout << res;
}