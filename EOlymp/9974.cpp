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

    long long res = 0;
    for (long long i = 0, p = 1; i < n; i++, p *= 3)
        res += p;

    cout << res;
}