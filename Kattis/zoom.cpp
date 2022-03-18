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

    int size, d;
    cin >> size >> d;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    for (int i = d - 1; i < size; i += d)
        cout << a[i] << " ";
}