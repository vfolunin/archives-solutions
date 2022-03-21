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

    int distanceCount;
    cin >> distanceCount;

    vector<int> distances(distanceCount);
    for (int &distance : distances)
        cin >> distance;

    int res = 1e9;
    for (int i = 0; i < distanceCount; i++)
        res = min(res, distances[i] + distances[(i + 2) % distanceCount]);

    cout << res;
}