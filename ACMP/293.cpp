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

    vector<int> p(size);
    for (int &value : p)
        cin >> value;

    int res = 0;
    for (int i = 1; i < size; i++)
        if (a[res] * p[res] < a[i] * p[i])
            res = i;

    cout << res + 1;
}