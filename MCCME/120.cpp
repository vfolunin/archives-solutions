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

    double sum = 1, den = 1;
    for (int i = 1; i <= n; i++) {
        den *= i;
        sum += 1 / den;
    }

    cout << fixed << sum;
}