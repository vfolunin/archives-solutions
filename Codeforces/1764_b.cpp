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
    int gcdValue = 0;
    for (int &value : a) {
        cin >> value;

        gcdValue = gcd(gcdValue, value);
    }

    cout << *max_element(a.begin(), a.end()) / gcdValue << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}