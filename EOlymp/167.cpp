#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long root = sqrt(n);
    long long res = 0;
    for (long long d = 1; d <= root; d++)
        res += n / d;
    res = res * 2 - root * root;

    cout << res;
}