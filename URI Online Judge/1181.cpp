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

    for (int i = 0; i < n; i++) {
        double num, den;
        cin >> num >> den;

        if (den) {
            cout.precision(1);
            cout << fixed << num / den << "\n";
        } else {
            cout << "divisao impossivel\n";
        }
    }
}