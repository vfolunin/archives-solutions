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

    unsigned long long a, b;
    cin >> a >> b;

    if (a < b || (a - b) % 2) {
        cout << -1;
    } else {
        unsigned long long x = (a - b) / 2;
        if (x & b)
            cout << -1;
        else
            cout << x << " " << x + b;
    }
}