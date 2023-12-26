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

    if (a >= b && a >= c)
        cout << "Petryk";
    else if (b >= a && b >= c)
        cout << "Marichka";
    else
        cout << "Olenka";
}