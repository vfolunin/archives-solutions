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

    if (!a && !b && (c || d))
        cout << "INF";
    else if (a && b % a == 0 && c * (-b / a) + d)
        cout << -b / a;
    else
        cout << "NO";
}