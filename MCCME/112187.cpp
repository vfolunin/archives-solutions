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
        int remainder = n % -2;
        n /= -2;

        if (remainder == -1) {
            remainder = 1;
            n++;
        }

        res += remainder + '0';
    }

    reverse(res.begin(), res.end());
    if (res.empty())
        res += "0";

    cout << res;
}