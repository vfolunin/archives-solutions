#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int x11, y11, x12, y12;
    int x21, y21, x22, y22;
    cin >> x11 >> y11 >> x12 >> y12;
    cin >> x21 >> y21 >> x22 >> y22;

    int x1 = max(x11, x21), y1 = max(y11, y21);
    int x2 = min(x12, x22), y2 = min(y12, y22);

    if (test)
        cout << "\n";
    if (x1 < x2 && y1 < y2)
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    else
        cout << "No Overlap\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}