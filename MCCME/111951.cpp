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

    long long num, den;
    cin >> den >> num;

    long long l = -1, r = 1e9;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if ((num + m) * 3 < den + m)
            l = m;
        else
            r = m;
    }

    cout << r;
}