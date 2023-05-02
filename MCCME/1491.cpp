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

    double value;
    cin >> value;

    if (value > 0)
        cout << 1;
    else if (value == 0)
        cout << 0;
    else
        cout << -1;
}