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

    long long x;
    int p;
    cin >> x >> p;

    if (x == 1) {
        cout << 1;
        return 0;
    }

    long long res = 1;
    for (int i = 0; i < p; i++)
        res *= x;

    cout << res;
}