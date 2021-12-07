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

    if (a + b == 160)
        cout << "0\n";
    else if (a + b > 160)
        cout << "1\n";
    else
        cout << "2\n";
}