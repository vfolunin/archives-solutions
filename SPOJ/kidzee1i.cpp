#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int aLimit, bLimit, cLimit;
    cin >> aLimit >> bLimit >> cLimit;

    cout << "Case " << test << ":\n";
    for (int a = 0; a <= aLimit; a++)
        for (int b = a + 1; b <= bLimit; b++)
            for (int c = b + 1; c <= cLimit; c++)
                cout << a << " " << b << " " << c << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}