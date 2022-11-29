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

    int a, p, b;
    cin >> a >> p >> b;

    int res = 0;
    while (a < b) {
        res++;
        a += a * p / 100;
    }

    cout << res;
}