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

    if (n > 1 && (n - 1) % 11 == 0)
        cout << (n - 1) / 11 * 4;
    else
        cout << -1;
}