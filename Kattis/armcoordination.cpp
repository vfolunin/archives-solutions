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

    int x, y, r;
    cin >> x >> y >> r;

    cout << x - r << " " << y + r << "\n";
    cout << x + r << " " << y + r << "\n";
    cout << x + r << " " << y - r << "\n";
    cout << x - r << " " << y - r << "\n";
}