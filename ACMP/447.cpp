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

    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
        
        while (res % 10 == 0)
            res /= 10;

        res %= (int)1e6;
    }

    cout << res % 10;
}