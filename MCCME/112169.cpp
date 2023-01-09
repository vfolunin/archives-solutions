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

    if (x * x + y * y <= 1 && (x <= 0 || x <= y))
        cout << "YES";
    else
        cout << "NO";
}