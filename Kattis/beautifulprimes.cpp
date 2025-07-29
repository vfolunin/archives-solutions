#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    for (int count2 = 0, count11 = size; count2 <= size; count2++, count11--) {
        if (ceil(count2 * log10(2) + count11 * log10(11)) == size) {
            for (int i = 0; i < count2; i++)
                cout << "2 ";
            for (int i = 0; i < count11; i++)
                cout << "11 ";
            cout << "\n";
            return;
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