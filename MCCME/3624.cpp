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
    double x;
    cin >> n >> x;

    double num = 1, den = 1, sum = 1;
    for (int i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        sum += num / den;
    }

    cout << fixed << sum;
}