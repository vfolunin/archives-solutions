#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    int res1 = n * 2 - 1, res2 = 0;
    for (int i = 1; i < n; i++)
        res2 += sqrt((n - 0.5) * (n - 0.5) - i * i);

    if (test)
        cout << "\n";
    cout << "In the case n = " << n << ", " << 4 * res1 << " cells contain segments of the circle.\n";
    cout << "There are " << 4 * res2 << " cells completely contained in the circle.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}