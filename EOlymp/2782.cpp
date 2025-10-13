#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int area;
    cin >> area;
    area *= 2;

    int res = 0;
    for (int a = 1; a * a <= area; a++) {
        if (area % a)
            continue;

        int b = area / a;
        int c = sqrt(a * a + b * b);

        res += a * a + b * b == c * c;
    }

    cout << res;
}