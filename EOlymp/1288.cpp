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

    int n, a, b;
    cin >> n >> a >> b;

    if (!a && !b)
        cout << 0;
    else if (!a || !b || a == b)
        cout << "1" << string(n - 1, '0');
    else
        cout << "2" << string(n - 1, '0');
}