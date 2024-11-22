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

    string s;
    vector<int> a(size);
    for (int &value : a)
        cin >> s >> value;

    sort(a.rbegin(), a.rend());

    long long res = 0;
    for (int i = 0; i < a.size(); i += 2)
        res += a[i];

    cout << res;
}