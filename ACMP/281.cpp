#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, threshold;
    cin >> size >> threshold;

    int res = 0;
    for (int mask = 0; mask < (1 << size); mask++)
        res += ones(mask) >= threshold;

    cout << res;
}