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
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    if (a[1] - a[0] == a[2] - a[1])
        cout << a[2] + a[2] - a[1];
    else if (a[1] - a[0] < a[2] - a[1])
        cout << a[1] + a[1] - a[0];
    else
        cout << a[1] - (a[2] - a[1]);
}