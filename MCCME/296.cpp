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

    if (a == b && a == c)
        cout << 3;
    else if (a == b || a == c || b == c)
        cout << 2;
    else
        cout << 0;
}