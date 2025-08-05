#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int threshold, long long time) {
    long long count = 0;
    for (int value : a)
        count += time / value;
    return count >= threshold;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, threshold;
    cin >> size >> threshold;
    threshold++;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long l = 0, r = 1;
    while (!can(a, threshold, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, threshold, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}