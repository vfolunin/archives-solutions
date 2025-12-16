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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > d && b > c)
        cout << "Batman";
    else if (c > a && d > b)
        cout << "Superman";
    else
        cout << "Inconclusive";
}