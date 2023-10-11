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

    long long h, s;
    cin >> h >> s;

    long long d = 1;
    while ((d + 1) * (d + 1) * 4 <= h * h * 3)
        d++;

    cout << (s + d - 1) / d - 1;
}