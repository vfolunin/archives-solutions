#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool hasOddDigits(int n) {
    for ( ; n; n /= 10)
        if (n % 10 % 2 == 0)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
        if (hasOddDigits(i))
            cout << i << " ";
}