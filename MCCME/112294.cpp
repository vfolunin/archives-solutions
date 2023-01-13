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

    partial_sort(a.begin(), a.begin() + 3, a.end());

    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
}