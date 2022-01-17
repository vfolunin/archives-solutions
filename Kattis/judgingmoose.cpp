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

    if (!a && !b)
        cout << "Not a moose";
    else if (a == b)
        cout << "Even " << a + b;
    else
        cout << "Odd " << 2 * max(a, b);
}