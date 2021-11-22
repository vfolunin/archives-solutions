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

    vector<int> a(4);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    cout << abs(a[0] + a[3] - a[1] - a[2]) << "\n";
}