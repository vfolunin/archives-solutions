#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int a, int b) {
    if (a < b)
        return rec(b, a);
    if (!b)
        return 0;
    return rec(a - b, b) + b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << rec(a, b);
}