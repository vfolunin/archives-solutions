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

    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] + sum < i + 1) {
            cout << "NO\n";
            return;
        }
        sum = a[i] + sum - i - 1;
    }
    
    cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}