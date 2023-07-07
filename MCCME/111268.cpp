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

    vector<int> pos(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        pos[value - 1] = i;
    }

    int l = pos[0], r = pos[0], res = 1;
    for (int i = 1; i < size; i++) {
        l = min(l, pos[i]);
        r = max(r, pos[i]);
        res += r - l + 1 == i + 1;
    }

    cout << res;
}