#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int minDigit(int n) {
    int res = 9;
    while (n) {
        res = min(res, n % 10);
        n /= 10;
    }
    return res;
}

int maxDigit(int n) {
    int res = 0;
    while (n) {
        res = max(res, n % 10);
        n /= 10;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
 
    cout << minDigit(n) << " " << maxDigit(n);
}