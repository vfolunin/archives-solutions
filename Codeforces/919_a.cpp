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

    int shopCount, amount;
    cin >> shopCount >> amount;

    double res = 1e9;
    for (int i = 0; i < shopCount; i++) {
        double num, den;
        cin >> num >> den;

        res = min(res, amount * num / den);
    }

    cout << fixed << res;
}