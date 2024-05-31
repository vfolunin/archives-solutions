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

    int sum;
    cin >> sum;

    bool found = 0;
    for (int a = 1; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            if (a + b + a == sum) {
                cout << a << b << a << " ";
                found = 1;
            }
        }
    }

    if (!found)
        cout << "No";
}