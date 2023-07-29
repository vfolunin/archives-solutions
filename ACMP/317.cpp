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

    int a, b, c, sum;
    cin >> a >> b >> c >> sum;

    int res = 0;
    for (int ka = 0; ka * a <= sum; ka++)
        for (int kb = 0; ka * a + kb * b <= sum; kb++)
            res += (sum - ka * a - kb * b) % c == 0;

    cout << res;
}