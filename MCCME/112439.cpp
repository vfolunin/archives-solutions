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

    int a = -1, b = -1;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        if (value % 49 == 0)
            continue;
        else if (value % 7)
            a = max(a, value);
        else
            b = max(b, value);
    }

    if (a == -1 || b == -1)
        cout << 1;
    else
        cout << 1LL * a * b;
}