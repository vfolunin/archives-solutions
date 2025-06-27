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

    int type;
    vector<int> a = { 0, 0, 3 };
    cin >> type >> a[0];

    if (type == 1)
        a[1] = a[0];
    else if (type == 2)
        cin >> a[1];
    else
        cin >> a[1] >> a[2];

    cout << a[0] * a[1] * a[2] - (a[0] - 2) * (a[1] - 2) * (a[2] - 1);
}