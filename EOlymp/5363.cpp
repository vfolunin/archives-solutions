#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int delta, long long limit) {
    long long sum = 0;
    for (int value : a)
        sum += (max(value - limit, 0LL) + delta - 2) / (delta - 1);
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

    int delta;
    cin >> delta;

    if (delta <= 1) {
        cout << *max_element(a.begin(), a.end());
        return 0;
    }

    long long l = 0, r = 1;
    while (!can(a, delta, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, delta, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}