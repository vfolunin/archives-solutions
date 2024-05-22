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

    string ops;
    while (n > 1) {
        if (n % 3) {
            n--;
            ops += "1";
        } else {
            n /= 3;
            ops += "3";
        }
    }
    reverse(ops.begin(), ops.end());

    cout << ops;
}