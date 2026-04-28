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

    vector<int> a(2 * size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    cout << (a[size - 1] < a[size] ? "YES" : "NO");
}