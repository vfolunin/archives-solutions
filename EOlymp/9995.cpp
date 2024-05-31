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
        for (int b = 0; b < a; b++)
            for (int c = 0; c < b; c++)
                if (a + b + c == sum)
                    res += a * 100 + b * 10 + c;

    cout << res;
}