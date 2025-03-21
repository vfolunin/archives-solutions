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

    vector<int> b = a;
    sort(b.begin(), b.end());

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i];

    cout << res;
}