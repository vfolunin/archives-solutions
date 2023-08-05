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

    int res = sum;
    while (res + (res + 99) / 100 * 7 > sum)
        res--;

    cout << res << " " << (res + 99) / 100 * 7;
}