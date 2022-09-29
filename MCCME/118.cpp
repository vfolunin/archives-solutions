#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int reverse(int n) {
    int res = 0;
    while (n > 9) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    res = res * 10 + n;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << reverse(n);
}