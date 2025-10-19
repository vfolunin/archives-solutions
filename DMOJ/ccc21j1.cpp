#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    cout << 5 * t - 400 << "\n";

    if (t < 100)
        cout << 1;
    else if (t == 100)
        cout << 0;
    else
        cout << -1;
}