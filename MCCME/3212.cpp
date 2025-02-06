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

    int n;
    cin >> n;

    int res = 0;
    for (int a = 1; a <= 9; a++)
        for (int b = a + 1; b <= 9; b++)
            for (int c = 1; c <= 9; c++)
                for (int d = c + 1; d <= 9; d++)
                    for (int e = 1; e <= 9; e++)
                        res += a + b + c + d + e == n;

    cout << res;
}