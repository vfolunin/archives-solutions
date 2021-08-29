#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &arc, int sideCount, int sideLength) {
    for (int from = 0; 1; from++) {
        bool ok = 1;
        int len = from ? arc[from - 1] : 0;
        for (int i = 0; ok && i < sideCount; i++) {
            ok &= binary_search(arc.begin(), arc.end(), len + sideLength);
            len += sideLength;
        }
        if (ok)
            return 1;
        if (arc[from] > sideLength)
            break;
    }
    return 0;
}

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<int> arc(pointCount);
    for (int &a : arc)
        cin >> a;

    arc.insert(arc.end(), arc.begin(), arc.end());
    for (int i = 1; i < arc.size(); i++)
        arc[i] += arc[i - 1];
    
    int length = arc.back() / 2;

    for (int sideCount = pointCount; sideCount >= 3; sideCount--) {
        if (length % sideCount)
            continue;
        if (can(arc, sideCount, length / sideCount)) {
            cout << pointCount - sideCount << "\n";
            return 1;
        }
    }

    cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}