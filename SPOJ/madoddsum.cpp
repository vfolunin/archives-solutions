#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long oddSumTo(long long r) {
    r = (r + 1) / 2;
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    if (l > r)
        swap(l, r);

    cout << oddSumTo(r) - oddSumTo(l - 1);
}