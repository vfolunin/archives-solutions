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

    int a, b, n;
    cin >> a >> b >> n;

    int maxA = min(a, n);
    int maxB = min(b, n), minA = n - maxB;

    cout << maxA - minA + 1 << "\n";
}