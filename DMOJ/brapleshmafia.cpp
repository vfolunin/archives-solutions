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

    int size, mod;
    cin >> size >> mod;

    long long res = 0;
    for (int i = 0; i < size; i++) {
        long long a, b;
        cin >> a >> b;

        res = (res + a * b) % mod;
    }

    cout << res;
}