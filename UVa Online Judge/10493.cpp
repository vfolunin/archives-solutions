#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int degree, leafCount;
    cin >> degree >> leafCount;

    if (!degree && !leafCount)
        return 0;

    cout << degree << " " << leafCount << " ";
    if (degree == 1) {
        cout << (leafCount == 1 ? "Multiple\n" : "Impossible\n");
    } else {
        if ((leafCount - 1) % (degree - 1))
            cout << "Impossible\n";
        else
            cout << (leafCount - 1) / (degree - 1) * degree + 1 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}