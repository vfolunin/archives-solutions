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

    string res;
    while (n) {
        int mod = n - n / -2 * -2;
        if (mod < 0)
            mod += 2;
        res += mod + '0';
        n = (n - mod) / -2;
    }
    reverse(res.begin(), res.end());

    cout << (res.empty() ? "0" : res);
}