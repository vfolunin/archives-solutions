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

    long long limit;
    cin >> limit;

    int res = 0;

    for (int size = 9; size; size--) {
        if (stoll('1' + string(size, '0')) <= limit) {
            res += size;
            break;
        }
    }

    res = max(res, 1);

    for (int digit = 1; digit <= 9; digit++) {
        for (int size = 9; size; size--) {
            if (stoll(string(size, digit + '0')) <= limit) {
                res += size;
                break;
            }
        }
    }

    cout << res;
}