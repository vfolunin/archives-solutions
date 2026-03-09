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

    int a, b, k;
    cin >> a >> b >> k;

    if ((a * (k - 1) - (b - a)) % (1 - k) == 0 && a * (k - 1) < (b - a))
        cout << a + (a * (k - 1) - (b - a)) / (1 - k);
    else
        cout << -1;
}