#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);
    for (int l = 1, r = 2; r < a.size(); l += 2, r += 2)
        swap(a[l], a[r]);

    for (int value : a)
        cout << value << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}