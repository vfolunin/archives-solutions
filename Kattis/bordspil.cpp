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

    cout << (a / 3 * 2 + (a % 3 == 2) + 2 > b ? "Arnar" : "Unnar");
}