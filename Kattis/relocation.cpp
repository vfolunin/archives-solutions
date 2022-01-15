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

    int pointCount, queryCount;
    cin >> pointCount >> queryCount;

    vector<int> points(pointCount);
    for (int &point : points)
        cin >> point;

    for (int i = 0; i < queryCount; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
            points[a - 1] = b;
        else
            cout << abs(points[a - 1] - points[b - 1]) << "\n";
    }
}