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

    long long height, width, hitCount, missCount;
    cin >> height >> width >> hitCount >> missCount;

    long long rowLimit = height / 3, colLimit = width / 3, shipLimit = rowLimit * colLimit;

    long long minShipCount = (hitCount + 7) / 8, maxShipCount = min((height * width - missCount) / 8, shipLimit);

    if (height * width < hitCount + missCount || shipLimit * 8 < hitCount || height * width - minShipCount * 8 < missCount)
        cout << "BAZINGA!";
    else
        cout << minShipCount << " " << maxShipCount;
}