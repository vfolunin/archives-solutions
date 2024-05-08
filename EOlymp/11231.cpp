#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> a, int limit, int h) {
    sort(a.rbegin(), a.rend());

    for (int &value : a) {
        if (value < h && limit) {
            value++;
            limit--;
        }
    }

    int count = 0;
    for (int value : a)
        count += value >= h;

    return count >= h;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int l = 0, r = 1;
    while (can(a, limit, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, limit, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}