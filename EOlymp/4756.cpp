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

    int n, d;
    cin >> n >> d;

    if (n == d) {
        cout << -1;
        return 0;
    }

    int res = 0;
    for (int i = 1; i < n; i++)
        res += n % i == d;

    cout << res;
}