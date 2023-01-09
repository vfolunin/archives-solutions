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

    double x, y;
    cin >> x >> y;

    if (x * x - 2 <= y && (x <= 0 && y <= -x || x > 0 && y <= x))
        cout << "YES";
    else
        cout << "NO";
}