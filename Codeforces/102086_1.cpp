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

    long long l, r, a;
    cin >> l >> r >> a;

    long long len = r - l + 1;
    long long biggerGroups = len % a, biggerGroupSize = len / a + 1;
    long long smallerGroups = a - biggerGroups, smallerGroupSize = len / a;

    long long res = biggerGroups * biggerGroupSize * (biggerGroupSize - 1) / 2;
    res += smallerGroups * smallerGroupSize * (smallerGroupSize - 1) / 2;

    cout << res;
}