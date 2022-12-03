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

    double sum = 0;
    for (int i = 0; i <= n; i++)
        sum += 1.0 / (2 * i + 1) * (i % 2 ? -1 : 1);

    cout << fixed << sum;
}