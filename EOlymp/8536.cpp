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

    int t, a, b;
    cin >> t >> a >> b;

    cout << 4 * a - 3 * t - 3 * b;
}