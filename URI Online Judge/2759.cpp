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

    char a, b, c;
    cin >> a >> b >> c;

    cout << "A = " << a << ", B = " << b << ", C = " << c << "\n";
    cout << "A = " << b << ", B = " << c << ", C = " << a << "\n";
    cout << "A = " << c << ", B = " << a << ", C = " << b << "\n";
}