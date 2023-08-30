#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long turns(long long h, long long w) {
    if (h > w)
        return turns(w, h);
    if (h == 1)
        return 0;
    if (h == 2)
        return 2;
    return 2 * (h - 2) + turns(2, w - h + 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long h, w, a, b, c;
    cin >> h >> w >> a >> b >> c;

    cout << turns(h, w) * min(a, b) + (h * w - 1) * c;
}