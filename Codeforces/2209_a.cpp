#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    long long limit, incLimit;
    cin >> size >> limit >> incLimit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    for (int value : a) {
        if (value <= limit) {
            long long delta = min(limit - value, incLimit);
            value += delta;
            incLimit -= delta;
            limit += value;
        }
    }

    cout << limit << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}