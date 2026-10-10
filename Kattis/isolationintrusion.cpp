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

    int delta;
    cin >> delta;

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    a[0] += delta;

    if (a[0] < a[1])
        cout << a[0];
    else
        cout << "impossible";
}