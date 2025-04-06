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

    int h, w, queryCount;
    cin >> h >> w >> queryCount;

    unordered_set<int> values;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            values.insert(value);
        }
    }

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        cout << (values.count(value) ? "YES\n" : "NO\n");
    }
}