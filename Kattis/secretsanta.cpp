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

    int size;
    cin >> size;

    double res = 1, factorial = 1;
    for (int i = 1; i <= size && i < 100; i++) {
        factorial *= i;
        res += (i % 2 ? -1 : 1) / factorial;
    }

    cout << fixed << 1 - res;
}