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

    int amount;
    cin >> amount;

    amount = (amount + 99) / 100;

    int res = 0;
    for (int nominal : { 5, 2, 1 }) {
        res += amount / nominal;
        amount %= nominal;
    }

    cout << res;
}