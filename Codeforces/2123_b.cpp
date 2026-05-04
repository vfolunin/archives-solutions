#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, index, count;
    cin >> size >> index >> count;
    index--;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    cout << (count > 1 || a[index] == *max_element(a.begin(), a.end()) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}