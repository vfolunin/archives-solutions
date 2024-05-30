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

    int sum;
    cin >> sum;

    int res = 0;
    for (int a = 1, b = sum - 1; a <= 9; a++, b--)
        if (0 <= b && b < a)
            res += a * 10 + b;

    cout << res;
}