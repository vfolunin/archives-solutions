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

    int res = 1;
    for (int count = 2; count * (count + 1) <= 2 * sum; count++)
        if ((sum - count * (count + 1) / 2) % count == 0)
            res = count;

    cout << res;
}