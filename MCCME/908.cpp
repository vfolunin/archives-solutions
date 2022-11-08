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

    vector<int> res(size, 1e9);
    res[1] = a[1] - a[0];

    for (int i = 2; i < size; i++)
        res[i] = a[i] - a[i - 1] + min(res[i - 1], res[i - 2]);

    cout << res[size - 1];
}