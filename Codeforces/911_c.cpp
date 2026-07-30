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

    if (a[0] == 1 || a[1] == 2 || a == vector{ 3, 3, 3 } || a == vector{ 2, 4, 4 })
        cout << "YES";
    else
        cout << "NO";
}