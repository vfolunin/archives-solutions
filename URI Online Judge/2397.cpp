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

    sort(a.begin(), a.end());

    if (a[0] + a[1] <= a[2])
        cout << "n\n";
    else if (a[0] * a[0] + a[1] * a[1] < a[2] * a[2])
        cout << "o\n";
    else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
        cout << "r\n";
    else
        cout << "a\n";
}