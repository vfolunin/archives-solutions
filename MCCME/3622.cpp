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
    double value;
    cin >> n >> value;

    double sum = 1, power = 1;
    for (int i = 1; i <= n; i++) {
        power *= value;
        sum += power;
    }

    cout << fixed << sum;
}