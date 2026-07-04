#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, long long threshold) {
    int count = 0;
    for (int value : a)
        count += value >= threshold * threshold;
    return count >= threshold;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long l = 0, r = size + 1;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}