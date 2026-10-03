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

    int rectangleCount;
    cin >> rectangleCount;

    int res = 0;
    for (int i = 0; i < rectangleCount; i++) {
        int h, w;
        cin >> h >> w;

        if (h == w)
            res = max(res, h);
    }

    cout << res << " " << res;
}