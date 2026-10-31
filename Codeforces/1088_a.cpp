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

    if (n == 1) {
        cout << "-1\n";
    } else {
        do {
            n++;
        } while (n % 4);

        cout << n / 2 << " 2\n";
    }
}