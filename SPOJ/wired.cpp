#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(4);
    for (int &value : a) {
        cin >> value;
        value--;
    }

    vector<int> pos(4);
    for (int i = 0; i < 4; i++) {
        int value;
        cin >> value;

        pos[value - 1] = i;
    }
    
    for (int value : a)
        cout << pos[value] + 1 << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}