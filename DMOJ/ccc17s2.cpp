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

    for (int l = (a.size() - 1) / 2, r = l + 1; r < a.size(); l--, r++)
        cout << a[l] << " " << a[r] << " ";
    if (a.size() % 2)
        cout << a[0];
}