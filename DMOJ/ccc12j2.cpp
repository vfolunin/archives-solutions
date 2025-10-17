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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b && b < c && c < d)
        cout << "Fish Rising";
    else if (a > b && b > c && c > d)
        cout << "Fish Diving";
    else if (a == b && b == c && c == d)
        cout << "Fish At Constant Depth";
    else
        cout << "No Fish";
}