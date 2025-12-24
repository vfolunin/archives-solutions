#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    unsigned int value;
    cin >> hex >> value;

    cout << hex << uppercase;
    if (value & (1 << 20))
        cout << setw(8) << setfill('0') << (value ^ (1 << 20)) << " ";
    cout << setw(8) << setfill('0') << value << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}