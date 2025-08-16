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

    double a, b, c;
    cin >> a >> b >> c;

    double sum = a / 4 + b / 4 + c / 2;

    if (sum >= 90)
        cout << "A";
    else if (sum >= 80)
        cout << "B";
    else if (sum >= 70)
        cout << "C";
    else if (sum >= 60)
        cout << "D";
    else
        cout << "F";
}