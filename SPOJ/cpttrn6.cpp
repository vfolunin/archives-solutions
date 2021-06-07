#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int rows, cols, h, w;
    cin >> rows >> cols >> h >> w;

    for (int y = 0; y < (rows + 1) * (h + 1) - 1; y++) {
        for (int x = 0; x < (cols + 1) * (w + 1) - 1; x++) {
            if (y % (h + 1) == h && x % (w + 1) == w)
                cout << "+";
            else if (y % (h + 1) == h)
                cout << "-";
            else if (x % (w + 1) == w)
                cout << "|";
            else
                cout << ".";
        }            
        cout << "\n";
    }
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