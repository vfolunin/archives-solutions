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

    vector<int> a(5);
    for (int &value : a)
        cin >> value;

    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i] << " ";
}