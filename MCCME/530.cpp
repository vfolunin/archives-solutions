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

    int size;
    cin >> size;

    int dist = 100, minDist = dist;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        dist = abs(dist + value);
        minDist = min(minDist, dist);
    }

    cout << minDist;
}