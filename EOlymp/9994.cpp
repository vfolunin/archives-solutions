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
    for (int a = 2; a < 10; a += 2)
        for (int b = 0; b < 10; b += 2)
            for (int c = 0; c < 10; c += 2)
                res += a + b + c == sum;

    cout << res;
}