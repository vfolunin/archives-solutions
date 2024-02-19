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

    long long l, r, d;
    cin >> l >> r >> d;

    cout << r / d - (l ? (l - 1) / d : -1);
}