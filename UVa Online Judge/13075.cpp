#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int cCount, vCount;
    cin >> cCount >> vCount;

    string s = string(cCount, 'C') + string(vCount, 'V');

    while (1) {
        cout << s;
        if (next_permutation(s.begin(), s.end())) {
            cout << " ";
        } else {
            cout << "\n";
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}