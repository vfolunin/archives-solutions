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

    vector<string> names(size);
    for (string &name : names)
        cin >> name;

    if (is_sorted(names.begin(), names.end()))
        cout << "INCREASING";
    else if (is_sorted(names.rbegin(), names.rend()))
        cout << "DECREASING";
    else
        cout << "NEITHER";
}