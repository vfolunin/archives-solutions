#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    while (n > 1) {
        cout << n << " ";
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
    }
    cout << n;
}