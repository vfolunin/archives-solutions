#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string text;
    cin >> text;

    int side = sqrt(text.size());
    
    for (int y = 0; y < side; y++)
        for (int x = 0; x < side; x++)
            cout << text[x * side + side - 1 - y];
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