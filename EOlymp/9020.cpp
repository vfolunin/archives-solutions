#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int partCount, long long limit) {
    long long sum = 0;
    int parts = 1;

    for (int value : a) {
        if (sum + value <= limit) {
            sum += value;
        } else {
            sum = value;
            parts++;
        }
    }

    return parts <= partCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, partCount;
    cin >> size >> partCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long r = *max_element(a.begin(), a.end()), l = r - 1;
    while (!can(a, partCount, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, partCount, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}