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

    int h, w, size;
    cin >> h >> w >> size;

    long long minY = 1e18, minX = 1e18;
    for (int i = 0; i < size; i++) {
        long long y, x;
        cin >> y >> x;

        minY = min(minY, y);
        minX = min(minX, x);
    }

    cout << minY * minX << " " << size;
}