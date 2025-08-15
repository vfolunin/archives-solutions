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

    int a, b, c, product;
    cin >> a >> b >> c >> product;

    if (a * b * c < product)
        cout << "TOO TIGHT";
    else if (a * b * c == product)
        cout << "COZY";
    else
        cout << "SO MUCH SPACE";
}