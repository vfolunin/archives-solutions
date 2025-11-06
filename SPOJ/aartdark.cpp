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

    double num = 0, den = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            char c;
            cin >> c;

            num += c == '*';
            den++;
        }
    }

    cout << num / den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}