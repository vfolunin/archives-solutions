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
    for (int a = 1; a < 10; a += 2)
        for (int b = 1; b < 10; b += 2)
            for (int c = 1; c < 10; c += 2)
                if (a + b + c == sum)
                    res += a * 100 + b * 10 + c;

    cout << res;
}