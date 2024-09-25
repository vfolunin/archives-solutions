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

    int size;
    cin >> size;

    const long long MOD = 1e9 + 7;
    long long res = 1;

    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        res = value % MOD * res % MOD;
    }

    cout << res;
}