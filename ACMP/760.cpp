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

    int pointCount, speed, distance;
    cin >> pointCount >> speed >> distance;

    double res = distance / (speed / 60.0);
    for (int i = 0; i < pointCount; i++) {
        int time;
        cin >> time >> time;
        res += time;
    }

    cout.precision(2);
    cout << fixed << res;
}