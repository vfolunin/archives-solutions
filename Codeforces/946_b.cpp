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

    long long a, b;
    cin >> a >> b;

    while (a && b) {
        if (a >= 2 * b)
            a %= 2 * b;
        else if (b >= 2 * a)
            b %= 2 * a;
        else
            break;
    }

    cout << a << " " << b;
}