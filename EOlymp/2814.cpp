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
    for (; n > 1; n /= 2) {
        if (n % 2)
            res = "X" + res;
        res = "S" + res;
    }

    cout << res;
}