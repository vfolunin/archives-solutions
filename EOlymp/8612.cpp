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

    int x;
    cin >> x;

    if (x >= 0)
        cout << x * x * x + 2 * x * x + 4 * x - 6;
    else
        cout << x * x * x - 7 * x;
}