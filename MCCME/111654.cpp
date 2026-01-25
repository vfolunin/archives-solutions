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

    int size, width;
    cin >> size >> width;

    map<int, int> delta;
    for (int i = 0; i < size; i++) {
        int l, r;
        cin >> l >> r;

        delta[l]++;
        delta[r + 1]--;
    }

    int from = 1, count = 0;
    for (auto &[coord, delta] : delta) {
        if (!count && from < coord) {
            cout << "NO";
            return 0;
        }
        count += delta;
        if (!count)
            from = coord - 1;
    }

    cout << (from == width ? "YES" : "NO");
}