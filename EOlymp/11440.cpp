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

    string a, b;
    cin >> a >> b;

    if (a == b)
        cout << a << " == " << b;
    else if (a.size() < b.size() || a.size() == b.size() && a < b)
        cout << a << " < " << b;
    else
        cout << a << " > " << b;
}