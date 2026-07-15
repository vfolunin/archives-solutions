#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(long long l, long long r, int value) {
    long long product = 1;
    int count = 0;

    for (int i = 1; product * value <= r; i++) {
        product *= value;
        long long factor = r / product;
        if (l <= factor * product)
            count = i;
    }

    return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    cout << min(getCount(l, r, 2), getCount(l, r, 5));
}