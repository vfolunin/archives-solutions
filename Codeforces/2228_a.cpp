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

    vector<int> count(3);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }
    
    int res = count[0];
    
    int delta = min(count[1], count[2]);
    res += delta;
    count[1] -= delta;
    count[2] -= delta;

    res += count[1] / 3;
    res += count[2] / 3;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}