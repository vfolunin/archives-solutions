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

    int a12, a13, a23;
    cin >> a12 >> a13 >> a23;

    if (a12 + a13 == a23)
        cout << 1;
    else if (a12 + a23 == a13)
        cout << 2;
    else if (a13 + a23 == a12)
        cout << 3;
    else
        cout << 0;
}