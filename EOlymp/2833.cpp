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

    vector<long long> a(size);
    long long target = 0;
    for (long long &value : a) {
        cin >> value;
        target += value;
    }
    target /= a.size();

    long long res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += abs(a[i] - target);
        if (i + 1 < a.size())
            a[i + 1] += a[i] - target;
    }

    cout << res;
}