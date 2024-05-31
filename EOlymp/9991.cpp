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
    for (int a = 1; a < 10; a++)
        for (int b = a + 1; b < 10; b++)
            for (int c = b + 1; c < 10; c++)
                res += a + b + c == sum;

    cout << res;
}