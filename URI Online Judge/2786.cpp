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

    int h, w;
    cin >> h >> w;

    cout << h * w + (h - 1) * (w - 1) << "\n";
    cout << 2 * (h + w - 2) << "\n";
}