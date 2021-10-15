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

    int a, b, c;
    cin >> a >> b >> c;

    if (a > b && b <= c)
        cout << ":)\n";
    else if (a < b && b >= c)
        cout << ":(\n";
    else if (a < b && b < c && b - a > c - b)
        cout << ":(\n";
    else if (a < b && b < c && b - a <= c - b)
        cout << ":)\n";
    else if (a > b && b > c && a - b > b - c)
        cout << ":)\n";
    else if (a > b && b > c && a - b <= b - c)
        cout << ":(\n";
    else if (a == b && b < c)
        cout << ":)\n";
    else if (a == b && b >= c)
        cout << ":(\n";
}