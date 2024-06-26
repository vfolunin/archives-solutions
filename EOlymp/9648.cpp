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

    long long res = 0;
    for (int i = l; i <= r; i++) {
        string s = to_string(i);
        sort(s.begin(), s.end());
        res += stoi(s);
    }

    cout << res;
}