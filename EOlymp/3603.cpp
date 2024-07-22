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

    vector<int> res(150, 1e9);

    for (int mask = 0; mask < 59049; mask++) {
        int sum = 0, bits = 0;
        for (int i = 0, m = mask; i < 10; i++, m /= 3) {
            if (m % 3 == 1)
                sum += 1 << i;
            else if (m % 3 == 2)
                sum -= 1 << i;
            bits += m % 3 != 0;
        }
        if (sum < res.size())
            res[sum] = min(res[sum], bits);
    }

    cout << res[n];
}