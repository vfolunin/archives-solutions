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

    vector<int> a(8);
    for (int &value : a)
        cin >> value;

    if (is_sorted(a.begin(), a.end()))
        cout << "ascending";
    else if (is_sorted(a.rbegin(), a.rend()))
        cout << "descending";
    else
        cout << "mixed";
}