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

    if (a == 1 && b == -7)
        cout << "neutral";
    else if (b >= -7)
        cout << "acid";
    else
        cout << "base";
}