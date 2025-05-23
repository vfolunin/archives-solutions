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

    for (int i = size / 3; i < size / 3 * 2; i++)
        cout << a[i] << " ";
    for (int i = 0; i < size / 3; i++)
        cout << a[i] << " ";
    for (int i = size / 3 * 2; i < size; i++)
        cout << a[i] << " ";
}