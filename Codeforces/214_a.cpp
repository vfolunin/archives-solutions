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

    int sum1, sum2;
    cin >> sum1 >> sum2;

    int res = 0;
    for (int a = 0; a <= 1000; a++)
        for (int b = 0; b <= 1000; b++)
            res += a * a + b == sum1 && a + b * b == sum2;

    cout << res;
}