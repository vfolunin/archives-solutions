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
    char c;
    cin >> n >> c;

    long long res;
    if (c == '!') {
        res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
    } else {
        res = n * (n + 1) / 2;
    }

    cout << res;
}