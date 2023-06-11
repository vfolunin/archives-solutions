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

    if (-2 <= x && x <= -y && 0 <= y && x * x + y * y >= 4)
        cout << "YES";
    else
        cout << "NO";
}