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

    long long a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = 1; i < 10; i++)
        res += a % (b * i) == 0;

    cout << res;
}