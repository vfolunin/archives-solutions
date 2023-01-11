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

    vector<int> a(5);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    cout << a[0] << " " << a[4] << "\n";
    cout.precision(2);
    cout << fixed << (a[1] + a[2] + a[3]) / 3.0;
}