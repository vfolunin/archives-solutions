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

    int sum = 0, res = 0;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;

        sum += x;
        if (abs(res - 100) >= abs(sum - 100))
            res = sum;
    }

    cout << res;
}