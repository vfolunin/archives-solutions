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

    int a, b, c;
    cin >> a >> b >> c;

    if (a == -1)
        cout << (b == 2);
    else if (b == -1)
        cout << (a == 4);
    else
        cout << (a == 4 && b == 2 ? 10 : 0);
}