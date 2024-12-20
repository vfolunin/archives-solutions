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

    int pointCount;
    cin >> pointCount;

    set<int> xs;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;
        xs.insert(x);
    }

    cout << xs.size();
}