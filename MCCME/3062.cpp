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

    double a, b;
    cin >> a >> b;

    int res = 1;
    while (a + 1e-9 < b) {
        res++;
        a *= 1.1;
    }

    cout << res;
}