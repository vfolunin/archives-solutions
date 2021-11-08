#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<int> a(size);
    long long sum = 0;
    for (int &x : a) {
        cin >> x;
        sum += x;
    }

    if (sum % size) {
        cout << "-1\n";
        return 1;
    }

    sum /= size;
    long long res = 0;

    for (int &x : a)
        res += abs(sum - x);

    cout << res / 2 + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}