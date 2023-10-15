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

    if (n % 3 == 0) {
        cout << "3 " << n / 3;
    } else if (n % 3 == 1) {
        cout << "2 2";
        if (n > 4)
            cout << " 3 " << (n - 4) / 3;
    } else {
        cout << "2 1";
        if (n > 2)
            cout << " 3 " << (n - 2) / 3;
    }
}