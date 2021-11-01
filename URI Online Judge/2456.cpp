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
    for (int &x : a)
        cin >> x;

    if (is_sorted(a.begin(), a.end()))
        cout << "C\n";
    else if (is_sorted(a.rbegin(), a.rend()))
        cout << "D\n";
    else
        cout << "N\n";
}