#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    int maxA = 0;
    long long sumB = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > b[i])
            swap(a[i], b[i]);
        maxA = max(maxA, a[i]);
        sumB += b[i];
    }

    cout << maxA + sumB << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}