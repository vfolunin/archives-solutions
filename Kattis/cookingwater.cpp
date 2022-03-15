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

    int segmentCount;
    cin >> segmentCount;

    int maxL = -1, minR = 1001;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        maxL = max(maxL, l);
        minR = min(minR, r);
    }

    if (maxL <= minR)
        cout << "gunilla has a point";
    else
        cout << "edward is right";
}