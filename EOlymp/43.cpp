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

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long num = b * c + a * c + a * b;
    long long den = a * b * c;

    if (num < den && d * den % (den - num) == 0) {
        long long res = d * den / (den - num);
        if (res % a == 0 && res % b == 0 && res % c == 0) {
            cout << res;
            return 0;
        }
    }

    cout << -1;
}