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

    cout << "Please enter the positive integer N:";

    int n;
    cin >> n;

    if (n > 0) {
        cout << "The number-triangle that has " << n << " lines is:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++)
                cout << i << " ";
            cout << "\n";
        }
    } else {
        cout << "N must be greater than 0!";
    }
}