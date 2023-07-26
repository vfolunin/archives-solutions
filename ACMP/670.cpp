#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int n) {
    vector<int> used(10);
    while (n) {
        if (used[n % 10])
            return 0;
        used[n % 10] = 1;
        n /= 10;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i++) {
        do {
            res++;
        } while (!isGood(res));
    }

    cout << res;
}