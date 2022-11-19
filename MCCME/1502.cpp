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

    vector<int> a(3), b(2);
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a[0] <= b[0] && a[1] <= b[1])
        cout << "YES";
    else
        cout << "NO";
}