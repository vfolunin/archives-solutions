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

    int res = 0;
    for (int coin : { 500, 200, 100, 50, 20, 10 }) {
        res += n / coin;
        n %= coin;
    }

    cout << (n % 10 == 0 ? res : -1);
}