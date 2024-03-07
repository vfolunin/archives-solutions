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

    double ab, ac, bc, v0, v1, v2;
    cin >> ab >> ac >> bc >> v0 >> v1 >> v2;

    ab = min(ab, ac + bc);
    ac = min(ac, ab + bc);

    cout << fixed << min({
        ab / v0 + bc / v1 + ac / v2,
        ac / v0 + bc / v1 + ab / v2,
        ab / v0 + ab / v1 + ac / v0 + ac / v1
    });
}