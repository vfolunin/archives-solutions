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

    vector<int> b(2);
    for (int &value : b)
        cin >> value;

    sort(b.begin(), b.end());

    cout << (a[0] <= b[0] && a[1] <= b[1] ? "YES" : "NO");
}