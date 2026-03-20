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

    for (int a = -999; a <= 999; a++) {
        int b = sum - a;
        if (a && b && -999 <= b && b <= 999) {
            cout << a << " " << b;
            break;
        }
    }
}