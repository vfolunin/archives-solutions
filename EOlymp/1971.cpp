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

    int n, k;
    cin >> n >> k;

    long long res = 1;
    for (int i = 0; i < k; i++)
        res *= (n - i) * (n - i);
    for (int i = 1; i <= k; i++)
        res /= i;

    cout << res;
}