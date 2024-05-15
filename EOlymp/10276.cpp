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

    if (a + d != b + c)
        cout << (a + d > b + c ? "U" : "P");
    else if (b != d)
        cout << (b > d ? "P" : "U");
    else
        cout << "T";
}