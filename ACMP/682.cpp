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

    if (n == 1)
        cout << 45;
    else if (n == 2)
        cout << 4905;
    else
        cout << 494 << string(n - 3, '9') << 55 << string(n - 2, '0');
}