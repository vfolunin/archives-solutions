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

    int size;
    cin >> size;

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    cout.precision(1);
    if (a.size() % 2)
        cout << fixed << a[a.size() / 2];
    else
        cout << fixed << (a[a.size() / 2 - 1] + a[a.size() / 2]) / 2;
}