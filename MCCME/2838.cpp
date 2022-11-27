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
    for (int &value : a)
        cin >> value;

    if (a[0] && a[2] || a[0] && a[3] || a[1] && a[3])
        cout << "YES";
    else
        cout << "NO";
}