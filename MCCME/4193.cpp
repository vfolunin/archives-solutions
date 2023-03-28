#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorSum(int n) {
    int sum = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n && d > 1)
                sum += n / d;
        }
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    for (int a = 1; a <= n; a++) {
        int b = getDivisorSum(a);
        if (a < b && b <= n && getDivisorSum(b) == a)
            cout << a << " " << b << "\n";
    }
}