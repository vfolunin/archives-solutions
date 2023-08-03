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

    int size, friendCount;
    cin >> size >> friendCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    long long res = 0;
    for (int i = 0, tryIndex = 1; i < size; tryIndex++)
        for (int friendIndex = 0; i < size && friendIndex < friendCount; i++, friendIndex++)
            res += tryIndex * a[i];

    cout << res;
}