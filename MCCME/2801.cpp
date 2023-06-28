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

    double a = 1;
    if (cin.peek() != 'x')
        cin >> a;

    char x, sign;
    double b;
    cin >> x >> sign >> b;

    if (a)
        cout << fixed << (sign == '+' ? -b : b) / a;
    else if (b)
        cout << "NO";
    else
        cout << "INF";
}