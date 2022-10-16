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

    int sum = 0;
    for (int i = 2; i <= n; i++) {
        cout << i - 1 << "*" << i << (i < n ? "+" : "=");
        sum += (i - 1) * i;
    }

    cout << sum;
}