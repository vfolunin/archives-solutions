#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<int> xs, ys;
    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;

        xs.insert(x);
        ys.insert(y);
    }

    cout << min(xs.size(), ys.size());
}