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

    int l, r;
    cin >> l >> r;

    string s = string(30, '0') + "11";
    int res = 0;

    do {
        long long value = stoll(s, 0, 2);
        res += l <= value && value <= r;
    } while (next_permutation(s.begin(), s.end()));

    cout << res;
}