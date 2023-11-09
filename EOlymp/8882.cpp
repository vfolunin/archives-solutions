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

    vector<long long> a(4);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    if (a[0] == a[3])
        cout << a[0] * a[0];
    else
        cout << "No";
}