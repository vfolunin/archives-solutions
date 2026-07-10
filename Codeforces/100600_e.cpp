#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    if (a < b)
        cout << b - a;
    else
        cout << b + 12 - a;
}