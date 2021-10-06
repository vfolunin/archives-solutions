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

    double n;
    cin >> n;

    cout.precision(4);
    for (int i = 0; i < 100; i++, n /= 2)
        cout << "N[" << i << "] = " << fixed << n << "\n";
}