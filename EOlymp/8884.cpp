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

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    if (a[0] + a[1] <= a[2])
        cout << "invalid";
    else if (a[0] == a[2])
        cout << "equilateral";
    else if (a[0] == a[1] || a[1] == a[2])
        cout << "isosceles";
    else
        cout << "versatile";
}