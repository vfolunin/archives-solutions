#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(int n) {
    string s = to_string(n);
    for (int i = 0; i < 3; i++)
        if (s[i] < '1' || s[i] > '6' || s[i] - '0' + s[s.size() - 1 - i] - '0' != 7)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 1e5; i <= n; i++)
        res += check(i);

    cout << res;
}