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
    for (int l = 0; l <= 5; l++)
        for (int r = l; r <= 5; r++)
            res += l + r == n;

    cout << res;
}