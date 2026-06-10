#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("herons.in", "r", stdin);
    freopen("herons.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << max((a + 1) / 2, (b + 1) / 2) << " " << min(a, b);
}