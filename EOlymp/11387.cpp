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

    vector<long long> res(2);
    for (int i = 0, l = 0, r = a.size() - 1; i < a.size(); i++)
        res[i % 2] += (a[l] > a[r] ? a[l++] : a[r--]);

    cout << res[0] << " " << res[1];
}