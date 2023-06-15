#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int limit) {
    long long sum = 0;
    for (int value : a)
        sum += max(value - limit, 0);
    return sum <= limit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int l = 0, r = 2e9 + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}