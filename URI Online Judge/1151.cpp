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

    vector<long long> f = { 0, 1 };
    for (int i = 2; i < n; i++)
        f.push_back(f[i - 2] + f[i - 1]);

    for (int i = 0; i < n; i++)
        cout << f[i] << (i + 1 < n ? " " : "\n");
}