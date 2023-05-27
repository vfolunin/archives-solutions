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

    vector<int> res(n, 2);
    for (int i = n - 1; i >= 0; i--)
        for (int d = 1; d <= 9; d++)
            if (i + d >= res.size() || res[i + d] == 2)
                res[i] = 1;

    cout << res[0];
}