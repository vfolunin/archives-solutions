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

    for (int h = 2; 1; h++) {
        if ((a + b) % h)
            continue;

        int w = (a + b) / h;

        if (a == (h + w - 2) * 2 && b == (h - 2) * (w - 2)) {
            cout << w << " " << h;
            return 0;
        }
    }
}