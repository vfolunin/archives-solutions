#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    double r, n;
    cin >> r >> n;

    if (!r && !n)
        return 0;

    cout << "Case " << test << ":\n";
    for (int i = 1; i <= 10; i++) {
        double c = n / i;
        double cr = c / (2 * acos(-1));
        double angle = (acos(cr / r) - n / r) / acos(-1) * 180;

        cout.precision(5);
        cout << fixed << angle << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}