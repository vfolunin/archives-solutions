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

    int res = 0;
    while (a && b) {
        if (a < b)
            swap(a, b);
        res += a / b;
        a %= b;
    }

    cout << res;
}