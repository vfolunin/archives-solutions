#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int height, width, y, x;
    cin >> height >> width >> y >> x;

    cout << max(y - 1, height - y) + max(x - 1, width - x) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}