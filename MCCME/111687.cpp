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

    vector<int> res(30, 2);
    for (int i = res.size() - 1; i >= n; i--)
        for (int j : { i + 2, i * i })
            if (j >= res.size() || res[j] == 2)
                res[i] = 1;

    cout << (res[n] == 1 ? "YES" : "NO");
}