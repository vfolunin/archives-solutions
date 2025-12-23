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

    vector<int> a(size * 2);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < size; i++)
        res += a[size + i] - a[i];

    cout << res;
}