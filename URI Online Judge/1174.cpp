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

    for (int i = 0; i < 100; i++) {
        double x;
        cin >> x;

        if (x <= 10) {
            cout.precision(1);
            cout << "A[" << i << "] = " << fixed << x << "\n";
        }
    }
}