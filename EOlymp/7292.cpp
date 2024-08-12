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

    long long a, b, c, size;
    cin >> a >> b >> c >> size;

    long long amount = (a * 17 + b) * 29 + c;

    for (int i = 0; i < size; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        amount -= (a * 17 + b) * 29 + c;
    }

    if (amount >= 0)
        cout << amount / (17 * 29) << " " << amount % (17 * 29) / 29 << " " << amount % 29;
    else
        cout << -1;
}