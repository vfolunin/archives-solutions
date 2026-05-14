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

    int num, den, l, r;
    cin >> den >> num >> l >> r;

    if (l * den <= num && num <= r * den)
        cout << "S";
    else
        cout << "N";
}