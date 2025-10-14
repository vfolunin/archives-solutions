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

    if (a + b + c != 180)
        cout << "Error";
    else if (a == b && a == c)
        cout << "Equilateral";
    else if (a == b || a == c || b == c)
        cout << "Isosceles";
    else
        cout << "Scalene";
}