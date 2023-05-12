#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum;
    cin >> sum;

    for (int a = 1; a * a * 2 <= sum; a++) {
        int b = sqrt(sum - a * a);
        if (a * a + b * b == sum) {
            cout << a << " " << b;
            return 0;
        }
    }

    cout << "Impossible";
}