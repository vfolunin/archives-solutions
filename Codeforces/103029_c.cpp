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

    int a, b;
    cin >> a >> b;

    if (a - abs(a - b) - 1 >= 0)
        cout << 0;
    else
        cout << a + abs(a - b) + 1;
}