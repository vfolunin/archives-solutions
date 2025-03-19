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

    double a, b;
    cin >> a >> b;
    a = -a;

    double c = (a + b) / 2;

    if (abs(a) <= abs(b) && abs(a) <= abs(c))
        cout << "Marat";
    else if (abs(b) <= abs(a) && abs(b) <= abs(c))
        cout << "Zarina";
    else
        cout << "Jin";
}