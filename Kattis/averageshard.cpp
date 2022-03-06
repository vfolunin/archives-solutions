#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long aSize, bSize;
    cin >> aSize >> bSize;

    vector<long long> a(aSize);
    long long aSum = 0;
    for (long long &x : a) {
        cin >> x;
        aSum += x;
    }

    vector<long long> b(bSize);
    long long bSum = 0;
    for (long long &x : b) {
        cin >> x;
        bSum += x;
    }

    int res = 0;
    for (long long x : a)
        res += x * (aSize - 1) < (aSum - x) && x * bSize > bSum;
    
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}