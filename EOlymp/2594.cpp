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

    map<pair<int, int>, int> count;
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;
        maxCount = max(maxCount, ++count[{ x, y }]);
    }

    cout << maxCount;
}