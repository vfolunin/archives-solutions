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
    for (int &x : a)
        cin >> x;

    vector<int> b = a;
    sort(b.begin(), b.end());

    for (int x : b)
        cout << x << "\n";

    cout << "\n";

    for (int x : a)
        cout << x << "\n";
}