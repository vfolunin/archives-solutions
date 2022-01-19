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

    vector<int> v(size);
    for (int &x : v)
        cin >> x;

    for (int i = size - 1; i >= 0; i--)
        cout << v[i] << "\n";
}