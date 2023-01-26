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

    int n, a, b;
    cin >> n >> a >> b;

    int res = 0;
    for (int i = 0; i <= n && i <= a; i++)
        res += n - i <= b;

    cout << res;
}