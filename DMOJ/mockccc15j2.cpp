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

    int a, b, weight;
    cin >> a >> b >> weight;

    int l = -1, r = 101;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if ((100 - weight) * a + weight * m >= b * 100 - 50)
            r = m;
        else
            l = m;
    }

    if (r <= 100)
        cout << r;
    else
        cout << "DROP THE COURSE";
}