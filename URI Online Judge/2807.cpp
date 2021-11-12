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

    vector<long long> f = { 1, 1 };
    for (int i = 2; i <= 40; i++)
        f.push_back(f[i - 2] + f[i - 1]);

    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--)
        cout << f[i] << (i ? " " : "\n");
}