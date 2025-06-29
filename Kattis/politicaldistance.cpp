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

    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}