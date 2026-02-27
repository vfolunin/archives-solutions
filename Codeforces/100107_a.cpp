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

    int res = 1;
    for (int i = 2; i + 1 < a.size(); i++)
        if (a[res - 1] + a[res] + a[res + 1] < a[i - 1] + a[i] + a[i + 1])
            res = i;

    cout << a[res - 1] + a[res] + a[res + 1] << " " << res + 1;
}