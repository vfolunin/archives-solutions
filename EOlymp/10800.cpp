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

    long long res = 0;
    for (int h = 1; h * h <= n; h++)
        res += n / h - h + 1;

    cout << res;
}