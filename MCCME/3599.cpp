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

    int sum;
    cin >> sum;

    int res = 0;
    for (int coin : { 10, 5, 2, 1 }) {
        res += sum / coin;
        sum %= coin;
    }

    cout << res;
}