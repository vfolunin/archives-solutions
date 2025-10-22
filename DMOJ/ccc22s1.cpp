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
    for (int count4 = 0; count4 * 4 <= sum; count4++)
        res += (sum - count4 * 4) % 5 == 0;

    cout << res;
}