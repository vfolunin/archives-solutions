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

    vector<int> a(6);
    for (int &x : a)
        cin >> x;

    if (a[0] + a[1] + a[2] + a[5] >= a[3] + a[4])
        cout << "Middle-earth is safe.\n";
    else
        cout << "Sauron has returned.\n";
}