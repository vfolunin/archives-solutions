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

    if (n % 24 == 0)
        cout << n / 24 * 13 << " " << n / 24 * 7 << " " << n / 24 * 4;
    else
        cout << -1;
}