#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int len, int need) {
    for (int value : a)
        need -= value / len;
    return need <= 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, need;
    cin >> size >> need;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, m, need))
            l = m;
        else
            r = m;
    }

    cout << l;
}