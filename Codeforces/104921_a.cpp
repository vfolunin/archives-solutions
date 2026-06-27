#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    char x, y;
    cin >> x >> y;
    x -= 'a';
    y -= '1';

    for (int i = 0; i < 8; i++) {
        if (i != x)
            cout << (char)(i + 'a') << (char)(y + '1') << "\n";
        if (i != y)
            cout << (char)(x + 'a') << (char)(i + '1') << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}