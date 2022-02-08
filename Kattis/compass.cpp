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

    int a, b;
    cin >> a >> b;

    int delta = abs(a - b);
    delta = min(delta, 360 - delta);

    if ((a + delta) % 360 == b)
        cout << delta;
    else
        cout << -delta;
}