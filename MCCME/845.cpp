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

    int l, r, x;
    cin >> l >> r >> x;

    if (x < l)
        cout << "NO GRAD";
    else if (x < r)
        cout << "GRAD";
}