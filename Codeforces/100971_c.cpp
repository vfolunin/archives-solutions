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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int l = a[a.size() - 1] - a[0] + 1;
    int r = a[0] + a[1] - 1;

    if (l <= r)
        cout << "YES\n" << l;
    else
        cout << "NO";
}